#ifndef OPENANN_OPTIMIZATION_OPTIMIZER_H_
#define OPENANN_OPTIMIZATION_OPTIMIZER_H_

#include <Eigen/Core>
#include <string>

namespace OpenANN
{

class Optimizable;
class StoppingCriteria;

/**
 * @class Optimizer
 *
 * The common interface of all optimization algorithms.
 */
class Optimizer
{
public:
  virtual ~Optimizer() {}
  /**
   * Pass the objective function.
   * @param optimizable objective function, e. g. error function of an ANN
   */
  virtual void setOptimizable(Optimizable& optimizable) = 0;
  /**
   * Pass the stop criteria.
   * @param sc the parameters used to stop the optimization
   */
  virtual void setStopCriteria(const StoppingCriteria& sc) = 0;
  /**
   * Optimize until the optimization meets the stop criteria.
   */
  virtual void optimize() = 0;
  /**
   * Execute one optimization step.
   */
  virtual bool step() = 0;
  /**
   * Determine the best result.
   * @return the best parameter the algorithm found
   */
  virtual Eigen::VectorXd result() = 0;
  /**
   * Get the name of the optimization algorithm.
   * @return name of the optimization algorithm
   */
  virtual std::string name() = 0;
  /**
   * Get the error.
   * @return the error
   */
  virtual double error() = 0;
};

} // namespace OpenANN

#endif // OPENANN_OPTIMIZATION_OPTIMIZER_H_
