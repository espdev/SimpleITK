/*=========================================================================
*
*  Copyright Insight Software Consortium
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*         http://www.apache.org/licenses/LICENSE-2.0.txt
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*=========================================================================*/
#ifndef __sitkVersorTransform_h
#define __sitkVersorTransform_h

#include "sitkCommon.h"
#include "sitkTransform.h"

namespace itk
{
namespace simple
{

class SITKCommon_EXPORT VersorTransform
  : public Transform
{
public:
  typedef VersorTransform Self;
  typedef Transform Superclass;

// construct identity
  VersorTransform();

  VersorTransform( const VersorTransform & );

  explicit VersorTransform( const Transform & );

  VersorTransform( const std::vector< double > &versor,
                   const std::vector< double> &fixedCenter =
                   std::vector< double >(3, 0.0) );

  VersorTransform( const std::vector< double > &axis,
                   double angle,
                   const std::vector< double> &fixedCenter =
                   std::vector< double >(3, 0.0) );

  VersorTransform &operator=( const VersorTransform & );

/** fixed parameter */
  Self &SetCenter(const std::vector<double> &params);
  std::vector<double> GetCenter( ) const;


/** parameter */
  Self &SetRotation(const std::vector<double> &versor);
  Self &SetRotation(const std::vector<double> &axis,  double angle);
  std::vector<double> GetVersor() const;

  /** additional methods */
  std::vector<double> GetMatrix() const;
  Self &SetMatrix(const std::vector<double> &matrix, double tolerance = 1e-10);

protected:

  virtual void SetPimpleTransform( PimpleTransformBase *pimpleTransform );

private:

  using Superclass::AddTransform;

  void InternalInitialization(itk::TransformBase *transform);

  template <typename TransformType>
    void InternalInitialization(TransformType *transform);


  nsstd::function<void(const std::vector<double>&)> m_pfSetCenter;
  nsstd::function<std::vector<double>()> m_pfGetCenter;
  nsstd::function<void(const std::vector<double>&)> m_pfSetRotation1;
  nsstd::function<void(const std::vector<double>&,double)> m_pfSetRotation2;
  nsstd::function<std::vector<double>()> m_pfGetVersor;
  nsstd::function<std::vector<double>()> m_pfGetMatrix;
  nsstd::function<void(const std::vector<double>&, double)> m_pfSetMatrix;
};
}
}

#endif // __sitkVersorTransform_h
