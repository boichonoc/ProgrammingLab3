/**
 * @file expression_evaluation.h
 * @author Yevhenii Boiko (Boiko.Y.O@nmu.one) https://github.com/boichonoc?tab=repositories
 * @brief  expression evaluation header file:
 * 
 *              Functions prototype: 
 *                                  void EXPRESSION_EVALUATION_Task(void);
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef EXPRESSION_EVALUATION_H
#define EXPRESSION_EVALUATION_H

#include <stdio.h>
#include <string.h>

#define DEFUALT_X_VALUE             2.5f
#define DEFUALT_Y_VALUE             3.1f
#define DEFUALT_Z_VALUE             0.41f

/**
 * @brief Containe existing EXceptions Code
 * 
 */
typedef enum ExceptionsCode
{
    EXCEPTION_NONE = 0,
    EXCEPTION_ERROR_DENUM_IS_0 = 1
} excode_t;

/**
 * @brief Run EXPRESSION_EVALUATION_Task for calculating expression
 * 
 */
void EXPRESSION_EVALUATION_Task(void);

#endif