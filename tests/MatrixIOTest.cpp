#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <fstream>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(MatrixIOOpenData)
{
  std::string filename     = "../data/m3.csv";
  int         expectedSize = 3;

  MatrixXd expected(3, 3);
  expected << 0.680375, 0.59688, -0.329554,
      -0.211234, 0.823295, 0.536459,
      0.566198, -0.604897, -0.444451;

  MatrixXd actual = matrixIO::openData(filename, expectedSize);

  BOOST_CHECK_EQUAL(actual.rows(), expected.rows());
  BOOST_CHECK_EQUAL(actual.cols(), expected.cols());

  for (int i = 0; i < expectedSize; ++i) {
    for (int j = 0; j < expectedSize; ++j) {
      BOOST_CHECK_CLOSE(actual(i, j), expected(i, j), 1e-4);
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()