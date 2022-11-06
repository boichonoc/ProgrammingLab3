/**
 * @file expression_evaluation.c
 * @author Yevhenii Boiko (Boiko.Y.O@nmu.one) https://github.com/boichonoc?tab=repositories
 * @brief expression evaluation source file:
 *
 *              Global functions:
 *                      void EXPRESSION_EVALUATION_Task(void);
 * 
 *              Static functions prototype:
 *                      static excode_t calculate(double *entering_param, double *sum_result);
 *                      static double calculate_numerator(double x, double y, double z);
 *                      static double calculate_denumerator(double x, double y, double z);
 *
 * @version 0.1
 * @date 2022-11-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "expression_evaluation.h"

/**
 * @brief Evaluates the full expression for entering params value
 *
 * @param entering_param : double* : apply array of entering args
 * @param sum_result : double* : apply pointer to sum result variable
 * @return excode_t
 */
static excode_t calculate(double *entering_param, double *sum_result);
/**
 * @brief Calculate numerator after checking of x by zero
 *
 * @param num_result
 * @param x
 * @param y
 * @param z
 * @return excode_t
 */
static excode_t calculate_numerator(double *num_result, double x, double y, double z);
/**
 * @brief Calculate denumerator and check denum_result by zero
 *
 * @param denum_result
 * @param x
 * @param y
 * @param z
 * @return excode_t
 */
static excode_t calculate_denumerator(double *denum_result, double x, double y, double z);

void EXPRESSION_EVALUATION_Task(void)
{
    static char input_command[2] = {0};
    static double input_value[3] = {0.0f};
    static double output_value = 0.0f;

    printf("-m - Manual input\n-d - Defualt param value\n");
    scanf("%s", input_command);
    if (strstr(input_command, "-m") != 0)
    {
        printf("Enter next one param: x, y, z\n");
        scanf("%lf%lf%lf", &input_value[0], &input_value[1], &input_value[2]);
    }
    else
    {
        input_value[0] = DEFUALT_X_VALUE;
        input_value[1] = DEFUALT_Y_VALUE;
        input_value[2] = DEFUALT_Z_VALUE;
        printf("Defualt param: x = %.2lf; y = %.2lf; z = %.2lf;\n", input_value[0], input_value[1], input_value[2]);
    }

    switch (calculate(input_value, &output_value))
    {
        case EXCEPTION_ERROR_DENUM_IS_0:
        {
            printf("Exception rised: EXCEPTION_ERROR_DENUM_IS_0\n");
        }
        break;

        case EXCEPTION_NONE:
        {
            printf("Input param: x = %.2f; y = %.2f; z = %.2f;\nOutput sum result: %.2f\n", input_value[0], input_value[1], input_value[2], output_value);
        }
        break;
    }
}

static excode_t calculate(double *entering_param, double *sum_result)
{
    double num_result = 0.0f;
    double denum_result = 0.0f;

    if (calculate_numerator(&num_result, entering_param[0], entering_param[1], entering_param[2]) == EXCEPTION_NONE)
    {
        if (calculate_denumerator(&denum_result, entering_param[0], entering_param[1], entering_param[2]) == EXCEPTION_NONE)
        {
            volatile double div_result = num_result / denum_result;
            (*sum_result) = div_result + (12 * entering_param[0]);

            return EXCEPTION_NONE;
        }
        else
        {
            return EXCEPTION_ERROR_DENUM_IS_0;
        }
    }
    else
    {
        return EXCEPTION_ERROR_DENUM_IS_0;
    }
}

static excode_t calculate_numerator(double *num_result, double x, double y, double z)
{
    (*num_result) = (-1.6 * y) * (1.4 * z);
    if (x == 0)
    {
        return EXCEPTION_ERROR_DENUM_IS_0;
    }
    (*num_result) = (*num_result) / x;
    (*num_result) = x - (*num_result) - 5;

    return EXCEPTION_NONE;
}

static excode_t calculate_denumerator(double *denum_result, double x, double y, double z)
{
    (*denum_result) = 1.6 * z;
    (*denum_result) = x - y + (*denum_result);

    if ((*denum_result) == 0)
    {
        return EXCEPTION_ERROR_DENUM_IS_0;
    }

    return EXCEPTION_NONE;
}