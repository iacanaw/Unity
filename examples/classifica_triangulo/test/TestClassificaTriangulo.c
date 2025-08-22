#include "unity.h"
#include "unity_fixture.h"
#include "classifica_triangulo.h"
#include <limits.h>

#ifndef STR_EQUILATERO
#define STR_EQUILATERO "equilatero"
#endif
#ifndef STR_ISOSCELES
#define STR_ISOSCELES  "isosceles"
#endif
#ifndef STR_ESCALENO
#define STR_ESCALENO   "escaleno"
#endif
#ifndef STR_INVALIDO
#define STR_INVALIDO   "erro"
#endif

TEST_GROUP(ClassificaTriangulo);

TEST_SETUP(ClassificaTriangulo) { 
    // nada
}
TEST_TEAR_DOWN(ClassificaTriangulo) {
    // nada
}

static void assert_tri(int a, int b, int c, const char* esperado)
{
    const char* out = classifica_triangulo(a, b, c);
    TEST_ASSERT_NOT_NULL_MESSAGE(out, "classifica_triangulo retornou NULL");
    TEST_ASSERT_EQUAL_STRING(esperado, out);
}

// Lado zero / negativo
TEST(ClassificaTriangulo, T01_LadoZero_A011)   { assert_tri(0, 1, 1, STR_INVALIDO); }
TEST(ClassificaTriangulo, T02_LadoZero_1B01)   { assert_tri(1, 0, 1, STR_INVALIDO); }
TEST(ClassificaTriangulo, T03_LadoZero_11C0)   { assert_tri(1, 1, 0, STR_INVALIDO); }
TEST(ClassificaTriangulo, T04_LadoNeg_A111)    { assert_tri(-1, 1, 1, STR_INVALIDO); }
TEST(ClassificaTriangulo, T05_LadoNeg_1B11)    { assert_tri(1, -1, 1, STR_INVALIDO); }
TEST(ClassificaTriangulo, T06_LadoNeg_11Cneg)  { assert_tri(1, 1, -1, STR_INVALIDO); }

// Invalidos: a+b=c, a+c=b, b+c=a
TEST(ClassificaTriangulo, T07_Deg_ab_eq_c)     { assert_tri(1, 1, 2, STR_INVALIDO); }
TEST(ClassificaTriangulo, T08_Deg_ac_eq_b)     { assert_tri(1, 2, 1, STR_INVALIDO); }
TEST(ClassificaTriangulo, T09_Deg_bc_eq_a)     { assert_tri(2, 1, 1, STR_INVALIDO); }

// Violação estrita da desigualdade
TEST(ClassificaTriangulo, T10_Viola_ab_lt_c)   { assert_tri(1, 2, 4, STR_INVALIDO); }
TEST(ClassificaTriangulo, T11_Viola_ac_lt_b)   { assert_tri(1, 4, 2, STR_INVALIDO); }
TEST(ClassificaTriangulo, T12_Viola_bc_lt_a)   { assert_tri(4, 1, 2, STR_INVALIDO); }

// Isósceles na fronteira da invalidade
TEST(ClassificaTriangulo, T13_Isos_Deg)        { assert_tri(2, 2, 4, STR_INVALIDO); }

// Equiláteros
TEST(ClassificaTriangulo, T14_Equi_Min)        { assert_tri(1, 1, 1, STR_EQUILATERO); }
TEST(ClassificaTriangulo, T15_Equi_Interior)   { assert_tri(100, 100, 100, STR_EQUILATERO); }

// Isósceles válidos (logo acima da fronteira) + permutações
TEST(ClassificaTriangulo, T16_Isos_122)        { assert_tri(1, 2, 2, STR_ISOSCELES); }
TEST(ClassificaTriangulo, T17_Isos_223)        { assert_tri(2, 2, 3, STR_ISOSCELES); }
TEST(ClassificaTriangulo, T18_Isos_232)        { assert_tri(2, 3, 2, STR_ISOSCELES); }
TEST(ClassificaTriangulo, T19_Isos_322)        { assert_tri(3, 2, 2, STR_ISOSCELES); }

// Escalenos válidos (pouco acima da fronteira + permutações)
TEST(ClassificaTriangulo, T20_Esca_234)        { assert_tri(2, 3, 4, STR_ESCALENO); }
TEST(ClassificaTriangulo, T21_Esca_432)        { assert_tri(4, 3, 2, STR_ESCALENO); }
TEST(ClassificaTriangulo, T22_Esca_345)        { assert_tri(3, 4, 5, STR_ESCALENO); }

// Robustez com limites superiores (evitar overflow na verificação)
TEST(ClassificaTriangulo, T23_Isos_MaxMax1)    { assert_tri(INT_MAX, INT_MAX, 1, STR_ISOSCELES); }
TEST(ClassificaTriangulo, T24_Equi_Max)        { assert_tri(INT_MAX, INT_MAX, INT_MAX, STR_EQUILATERO); }
TEST(ClassificaTriangulo, T25_Isos_Max1Max)    { assert_tri(INT_MAX, 1, INT_MAX, STR_ISOSCELES); }
