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
//+++ Date   : 2022.06.05
//+++ Purpose: implement the 1d lobatto gauss point generator
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include "FE/QPointGeneratorBase.h"

/**
 * This class implement the generator of 1d gauss points
 */
class QPoint1DLobattoGenerator:public QPointGeneratorBase{
public:
    /**
     * constructor
     */
    QPoint1DLobattoGenerator(){}
public:
    /**
     * gauss point generation function
     * @param t_order the order of gauss point integration
     * @param t_meshtype the mesh type
     * @param t_ngp the number of gauss point
     * @param t_qpoints the vector which stores the coordinates and weights of gauss point
     */
    virtual void generateQPoints(const int &t_order,const MeshType &t_meshtype,int &t_ngp,vector<double> &t_qpoints) override;

};