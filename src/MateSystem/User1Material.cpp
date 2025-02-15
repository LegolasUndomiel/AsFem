//****************************************************************
//* This file is part of the AsFem framework
//* A Simple Finite Element Method program (AsFem)
//* All rights reserved, Yang Bai/M3 Group@CopyRight 2020-present
//* https://github.com/M3Group/AsFem
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Author : Yang Bai
//+++ Date   : 2022.08.26
//+++ Purpose: Calculate the material properties required by diffusion
//+++          element. In this code, we can define:
//+++           1) D
//+++           2) dD/dc
//+++          Standard benchmark test for 2d nonlinear diffusion equation
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "MateSystem/User1Material.h"

User1Material::User1Material(){
    srand(time(00));// for random seed
}
void User1Material::initMaterialProperties(const nlohmann::json &inputparams,
                                        const LocalElmtInfo &elmtinfo,
                                        const LocalElmtSolution &elmtsoln,
                                        MaterialsContainer &mate){
    //***************************************************
    //*** get rid of unused warning
    //***************************************************
    if(inputparams.size()||elmtinfo.m_dt||elmtsoln.m_gpU[0]||mate.getScalarMaterialsNum()){}

}

//********************************************************************
void User1Material::computeMaterialProperties(const nlohmann::json &inputparams,
                                           const LocalElmtInfo &elmtinfo,
                                           const LocalElmtSolution &elmtsoln,
                                           const MaterialsContainer &mateold,
                                           MaterialsContainer &mate){
    //**************************************************************
    //*** get rid of unused warning
    //**************************************************************
    if(inputparams.size()||elmtinfo.m_dt||elmtsoln.m_gpU[0]||
       mateold.getScalarMaterialsNum()||mate.getScalarMaterialsNum()){}

    //************************
    //*** here the poisson equation is:
    //*** div(sigma*grad(phi))=F
    mate.ScalarMaterial("sigma")=JsonUtils::getValue(inputparams,"sigma");// sigma
    mate.ScalarMaterial("dsigmadu")=0.0;// dsigma/dphi
    mate.ScalarMaterial("f")=JsonUtils::getValue(inputparams,"f");// F
    mate.ScalarMaterial("dfdu")=0.0;// dF/dphi
    mate.VectorMaterial("gradu")=elmtsoln.m_gpGradU[1];// the gradient of u

    mate.ScalarMaterial("myx")=1.0*rand()/RAND_MAX;
    if(elmtinfo.m_elmtid==elmtinfo.m_elmtsnum){
        if(elmtinfo.m_qpointid==elmtinfo.m_qpointsnum){
            mate.ScalarMaterial("myx")=1000.0;
        }
    }

}