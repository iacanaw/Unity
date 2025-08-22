#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(ClassificaTriangulo)
{
  RUN_TEST_CASE(ClassificaTriangulo, T01_LadoZero_A011);
  RUN_TEST_CASE(ClassificaTriangulo, T02_LadoZero_1B01);
  RUN_TEST_CASE(ClassificaTriangulo, T03_LadoZero_11C0);
  RUN_TEST_CASE(ClassificaTriangulo, T04_LadoNeg_A111);
  RUN_TEST_CASE(ClassificaTriangulo, T05_LadoNeg_1B11);
  RUN_TEST_CASE(ClassificaTriangulo, T06_LadoNeg_11Cneg);

  RUN_TEST_CASE(ClassificaTriangulo, T07_Deg_ab_eq_c);
  RUN_TEST_CASE(ClassificaTriangulo, T08_Deg_ac_eq_b);
  RUN_TEST_CASE(ClassificaTriangulo, T09_Deg_bc_eq_a);

  RUN_TEST_CASE(ClassificaTriangulo, T10_Viola_ab_lt_c);
  RUN_TEST_CASE(ClassificaTriangulo, T11_Viola_ac_lt_b);
  RUN_TEST_CASE(ClassificaTriangulo, T12_Viola_bc_lt_a);
  RUN_TEST_CASE(ClassificaTriangulo, T13_Isos_Deg);

  RUN_TEST_CASE(ClassificaTriangulo, T14_Equi_Min);
  RUN_TEST_CASE(ClassificaTriangulo, T15_Equi_Interior);

  RUN_TEST_CASE(ClassificaTriangulo, T16_Isos_122);
  RUN_TEST_CASE(ClassificaTriangulo, T17_Isos_223);
  RUN_TEST_CASE(ClassificaTriangulo, T18_Isos_232);
  RUN_TEST_CASE(ClassificaTriangulo, T19_Isos_322);

  RUN_TEST_CASE(ClassificaTriangulo, T20_Esca_234);
  RUN_TEST_CASE(ClassificaTriangulo, T21_Esca_432);
  RUN_TEST_CASE(ClassificaTriangulo, T22_Esca_345);

  RUN_TEST_CASE(ClassificaTriangulo, T23_Isos_MaxMax1);
  RUN_TEST_CASE(ClassificaTriangulo, T24_Equi_Max);
  RUN_TEST_CASE(ClassificaTriangulo, T25_Isos_Max1Max);
}
