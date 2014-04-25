#ifndef OPENANN_OPTIMIZATION_LBFGS_H_
#define OPENANN_OPTIMIZATION_LBFGS_H_

#include <OpenANN/optimization/Optimizer.h>
#include <OpenANN/optimization/StoppingCriteria.h>
#include <Eigen/Core>
#include <optimization.h>

namespace OpenANN
{

/**
 * @class LBFGS
 *
 * Limited storage Broyden-Fletcher-Goldfarb-Shanno.
 *
 * L-BFGS is a quasi-Newton optimization algorithm that uses a low-rank
 * approximation of the Hessian (second derivative).
 */
class LBFGS : public Optimizer
{
  StoppingCriteria stop;
  Optimizable* opt; // do not delete
  Eigen::VectorXd optimum;
  int iteration, n, m;
  Eigen::VectorXd parameters, gradient;
  double error_;
  alglib_impl::ae_state envState;
  alglib::minlbfgsstate state;
  alglib::real_1d_array xIn;
public:
  /**
   * Create L-BFGS optimizer.
   * @param m Number of corrections of the Hessian approximation update in
   *          BFGS scheme. Small values cause worse convergence, bigger values
   *          will not cause a considerably better convergence, but will
   *          decrease the performance.
   */
  LBFGS(int m = 10);
  virtual ~LBFGS() {}
  virtual void setStopCriteria(const StoppingCriteria& stop);
  virtual void setOptimizable(Optimizable& optimizable);
  virtual void optimize();
  virtual bool step();
  void initialize();
  void reset();
  virtual Eigen::VectorXd result();
  virtual std::string name();
  virtual double error();
};

} // namespace OpenANN

#endif // OPENANN_OPTIMIZATION_LBFGS_H_
