/*
 * IP_LQG_PCI6221_2015a.c
 *
 * Code generation for model "IP_LQG_PCI6221_2015a".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 17 12:37:41 2025
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IP_LQG_PCI6221_2015a.h"
#include "IP_LQG_PCI6221_2015a_private.h"
#include "IP_LQG_PCI6221_2015a_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double RTWinBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  2.0,
};

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_IP_LQG_PCI6221_2015a_T IP_LQG_PCI6221_2015a_B;

/* Continuous states */
X_IP_LQG_PCI6221_2015a_T IP_LQG_PCI6221_2015a_X;

/* Block states (auto storage) */
DW_IP_LQG_PCI6221_2015a_T IP_LQG_PCI6221_2015a_DW;

/* Real-time model */
RT_MODEL_IP_LQG_PCI6221_2015a_T IP_LQG_PCI6221_2015a_M_;
RT_MODEL_IP_LQG_PCI6221_2015a_T *const IP_LQG_PCI6221_2015a_M =
  &IP_LQG_PCI6221_2015a_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  IP_LQG_PCI6221_2015a_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  IP_LQG_PCI6221_2015a_output();
  IP_LQG_PCI6221_2015a_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  IP_LQG_PCI6221_2015a_output();
  IP_LQG_PCI6221_2015a_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void IP_LQG_PCI6221_2015a_output(void)
{
  /* local block i/o variables */
  real_T rtb_Divide2_c;
  real_T rtb_Biasremoval;
  int_T ci;
  real_T rtb_LQG;
  if (rtmIsMajorTimeStep(IP_LQG_PCI6221_2015a_M)) {
    /* set solver stop time */
    if (!(IP_LQG_PCI6221_2015a_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&IP_LQG_PCI6221_2015a_M->solverInfo,
                            ((IP_LQG_PCI6221_2015a_M->Timing.clockTickH0 + 1) *
        IP_LQG_PCI6221_2015a_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&IP_LQG_PCI6221_2015a_M->solverInfo,
                            ((IP_LQG_PCI6221_2015a_M->Timing.clockTick0 + 1) *
        IP_LQG_PCI6221_2015a_M->Timing.stepSize0 +
        IP_LQG_PCI6221_2015a_M->Timing.clockTickH0 *
        IP_LQG_PCI6221_2015a_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(IP_LQG_PCI6221_2015a_M)) {
    IP_LQG_PCI6221_2015a_M->Timing.t[0] = rtsiGetT
      (&IP_LQG_PCI6221_2015a_M->solverInfo);
  }

  /* StateSpace: '<Root>/LQG' */
  rtb_LQG = 0.0;
  for (ci = 0; ci < 5; ci++) {
    rtb_LQG += -IP_LQG_PCI6221_2015a_P.K[ci] *
      IP_LQG_PCI6221_2015a_X.LQG_CSTATE[ci];
  }

  /* End of StateSpace: '<Root>/LQG' */

  /* MATLAB Function: '<Root>/deadzone compensation ' */
  /* MATLAB Function 'deadzone compensation ': '<S2>:1' */
  /* '<S2>:1:2' */
  /* '<S2>:1:3' */
  if ((rtb_LQG < 0.25) && (rtb_LQG > 0.0)) {
    /* '<S2>:1:6' */
    /* '<S2>:1:7' */
    rtb_LQG = 0.25;
  } else {
    if ((rtb_LQG > -0.38) && (rtb_LQG < 0.0)) {
      /* '<S2>:1:8' */
      /* '<S2>:1:9' */
      rtb_LQG = -0.38;
    }
  }

  /* '<S2>:1:13' */
  IP_LQG_PCI6221_2015a_B.y = rtb_LQG;

  /* End of MATLAB Function: '<Root>/deadzone compensation ' */
  if (rtmIsMajorTimeStep(IP_LQG_PCI6221_2015a_M)) {
    /* S-Function Block: <S4>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = IP_LQG_PCI6221_2015a_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &IP_LQG_PCI6221_2015a_P.EncoderInput1_Channels,
                     &rtb_Divide2_c, &parm);
    }

    /* S-Function Block: <S6>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = IP_LQG_PCI6221_2015a_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &IP_LQG_PCI6221_2015a_P.EncoderInput_Channels,
                     &rtb_Biasremoval, &parm);
    }

    /* Product: '<S7>/Divide2' incorporates:
     *  Constant: '<S7>/Angle'
     *  Constant: '<S7>/Encoder resolution'
     */
    rtb_Divide2_c = rtb_Divide2_c * IP_LQG_PCI6221_2015a_P.Angle_Value /
      IP_LQG_PCI6221_2015a_P.Encoderresolution_Value;

    /* Fcn: '<S7>/Fcn' */
    IP_LQG_PCI6221_2015a_B.Fcn = rt_atan2d_snf(sin(rtb_Divide2_c), cos
      (rtb_Divide2_c));

    /* DataTypeConversion: '<S1>/Boolean to double 1' incorporates:
     *  Constant: '<S5>/Lower Limit'
     *  Constant: '<S5>/Upper Limit'
     *  Logic: '<S5>/AND'
     *  RelationalOperator: '<S5>/Lower Test'
     *  RelationalOperator: '<S5>/Upper Test'
     */
    IP_LQG_PCI6221_2015a_B.Booleantodouble1 =
      ((-IP_LQG_PCI6221_2015a_P.ALPHA_MAX <= IP_LQG_PCI6221_2015a_B.Fcn) &&
       (IP_LQG_PCI6221_2015a_B.Fcn <= IP_LQG_PCI6221_2015a_P.ALPHA_MAX));

    /* Sum: '<S6>/Bias removal' incorporates:
     *  Constant: '<S6>/Angle'
     *  Constant: '<S6>/Bias'
     *  Constant: '<S6>/Encoder resolution'
     *  Product: '<S6>/Divide2'
     */
    rtb_Biasremoval = rtb_Biasremoval * IP_LQG_PCI6221_2015a_P.Angle_Value_f /
      IP_LQG_PCI6221_2015a_P.Encoderresolution_Value_l -
      IP_LQG_PCI6221_2015a_P.Bias_Value;

    /* Fcn: '<S6>/Fcn' */
    IP_LQG_PCI6221_2015a_B.Fcn_b = rt_atan2d_snf(sin(rtb_Biasremoval), cos
      (rtb_Biasremoval));

    /* DataTypeConversion: '<S1>/Boolean to double 2' incorporates:
     *  Constant: '<S3>/Lower Limit'
     *  Constant: '<S3>/Upper Limit'
     *  Logic: '<S3>/AND'
     *  RelationalOperator: '<S3>/Lower Test'
     *  RelationalOperator: '<S3>/Upper Test'
     */
    IP_LQG_PCI6221_2015a_B.Booleantodouble2 = ((-IP_LQG_PCI6221_2015a_P.BETA_MAX
      <= IP_LQG_PCI6221_2015a_B.Fcn_b) && (IP_LQG_PCI6221_2015a_B.Fcn_b <=
      IP_LQG_PCI6221_2015a_P.BETA_MAX));
  }

  /* Step: '<S1>/Time delay' */
  if (IP_LQG_PCI6221_2015a_M->Timing.t[0] < IP_LQG_PCI6221_2015a_P.TIME_DELAY) {
    rtb_LQG = IP_LQG_PCI6221_2015a_P.Timedelay_Y0;
  } else {
    rtb_LQG = IP_LQG_PCI6221_2015a_P.Timedelay_YFinal;
  }

  /* End of Step: '<S1>/Time delay' */

  /* Fcn: '<S1>/Fcn' */
  IP_LQG_PCI6221_2015a_B.Fcn_n = ((real_T)(fabs
    (IP_LQG_PCI6221_2015a_B.Booleantodouble1) > 0.0) + (real_T)(fabs
    (IP_LQG_PCI6221_2015a_B.Booleantodouble2) > 0.0)) + (real_T)(fabs(rtb_LQG) >
    0.0);

  /* Switch: '<S1>/Motor switch' incorporates:
   *  Constant: '<S1>/Const motor'
   */
  if (IP_LQG_PCI6221_2015a_B.Fcn_n >=
      IP_LQG_PCI6221_2015a_P.Motorswitch_Threshold) {
    rtb_LQG = IP_LQG_PCI6221_2015a_B.y;
  } else {
    rtb_LQG = IP_LQG_PCI6221_2015a_P.Constmotor_Value;
  }

  /* End of Switch: '<S1>/Motor switch' */

  /* Saturate: '<S1>/Motor protection' */
  if (rtb_LQG > IP_LQG_PCI6221_2015a_P.V_MAX) {
    rtb_LQG = IP_LQG_PCI6221_2015a_P.V_MAX;
  } else {
    if (rtb_LQG < IP_LQG_PCI6221_2015a_P.V_MIN) {
      rtb_LQG = IP_LQG_PCI6221_2015a_P.V_MIN;
    }
  }

  /* Gain: '<S1>/Gain' incorporates:
   *  Saturate: '<S1>/Motor protection'
   */
  IP_LQG_PCI6221_2015a_B.Gain = IP_LQG_PCI6221_2015a_P.Gain_Gain * rtb_LQG;
  if (rtmIsMajorTimeStep(IP_LQG_PCI6221_2015a_M)) {
    /* S-Function Block: <S1>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) IP_LQG_PCI6221_2015a_P.AnalogOutput_RangeMode;
        parm.rangeidx = IP_LQG_PCI6221_2015a_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &IP_LQG_PCI6221_2015a_P.AnalogOutput_Channels,
                       &IP_LQG_PCI6221_2015a_B.Gain, &parm);
      }
    }
  }

  /* Switch: '<S1>/Sensors switch' incorporates:
   *  Constant: '<S1>/Const sensors'
   */
  if (IP_LQG_PCI6221_2015a_B.Fcn_n >=
      IP_LQG_PCI6221_2015a_P.Sensorsswitch_Threshold) {
    IP_LQG_PCI6221_2015a_B.Sensorsswitch[0] = IP_LQG_PCI6221_2015a_B.Fcn;
    IP_LQG_PCI6221_2015a_B.Sensorsswitch[1] = IP_LQG_PCI6221_2015a_B.Fcn_b;
  } else {
    IP_LQG_PCI6221_2015a_B.Sensorsswitch[0] =
      IP_LQG_PCI6221_2015a_P.Constsensors_Value[0];
    IP_LQG_PCI6221_2015a_B.Sensorsswitch[1] =
      IP_LQG_PCI6221_2015a_P.Constsensors_Value[1];
  }

  /* End of Switch: '<S1>/Sensors switch' */

  /* Clock: '<Root>/Clock' */
  IP_LQG_PCI6221_2015a_B.Clock = IP_LQG_PCI6221_2015a_M->Timing.t[0];
  if (rtmIsMajorTimeStep(IP_LQG_PCI6221_2015a_M)) {
  }
}

/* Model update function */
void IP_LQG_PCI6221_2015a_update(void)
{
  if (rtmIsMajorTimeStep(IP_LQG_PCI6221_2015a_M)) {
    rt_ertODEUpdateContinuousStates(&IP_LQG_PCI6221_2015a_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++IP_LQG_PCI6221_2015a_M->Timing.clockTick0)) {
    ++IP_LQG_PCI6221_2015a_M->Timing.clockTickH0;
  }

  IP_LQG_PCI6221_2015a_M->Timing.t[0] = rtsiGetSolverStopTime
    (&IP_LQG_PCI6221_2015a_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++IP_LQG_PCI6221_2015a_M->Timing.clockTick1)) {
      ++IP_LQG_PCI6221_2015a_M->Timing.clockTickH1;
    }

    IP_LQG_PCI6221_2015a_M->Timing.t[1] =
      IP_LQG_PCI6221_2015a_M->Timing.clockTick1 *
      IP_LQG_PCI6221_2015a_M->Timing.stepSize1 +
      IP_LQG_PCI6221_2015a_M->Timing.clockTickH1 *
      IP_LQG_PCI6221_2015a_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void IP_LQG_PCI6221_2015a_derivatives(void)
{
  int_T is;
  int_T ci;
  int_T ci_0;
  XDot_IP_LQG_PCI6221_2015a_T *_rtXdot;
  _rtXdot = ((XDot_IP_LQG_PCI6221_2015a_T *)
             IP_LQG_PCI6221_2015a_M->ModelData.derivs);

  /* Derivatives for StateSpace: '<Root>/LQG' */
  for (is = 0; is < 5; is++) {
    _rtXdot->LQG_CSTATE[is] = 0.0;
    for (ci = 0; ci < 5; ci++) {
      ci_0 = ci * 5 + is;
      _rtXdot->LQG_CSTATE[is] += ((IP_LQG_PCI6221_2015a_P.A[ci_0] -
        IP_LQG_PCI6221_2015a_ConstP.LQG_rtw_collapsed_sub_expr_0[ci_0]) -
        IP_LQG_PCI6221_2015a_ConstP.LQG_rtw_collapsed_sub_expr_1[ci_0]) *
        IP_LQG_PCI6221_2015a_X.LQG_CSTATE[ci];
    }

    _rtXdot->LQG_CSTATE[is] += IP_LQG_PCI6221_2015a_P.L[is] *
      IP_LQG_PCI6221_2015a_B.Sensorsswitch[0];
    _rtXdot->LQG_CSTATE[is] += IP_LQG_PCI6221_2015a_P.L[5 + is] *
      IP_LQG_PCI6221_2015a_B.Sensorsswitch[1];
  }

  /* End of Derivatives for StateSpace: '<Root>/LQG' */
}

/* Model initialize function */
void IP_LQG_PCI6221_2015a_initialize(void)
{
  /* S-Function Block: <S1>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) IP_LQG_PCI6221_2015a_P.AnalogOutput_RangeMode;
      parm.rangeidx = IP_LQG_PCI6221_2015a_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &IP_LQG_PCI6221_2015a_P.AnalogOutput_Channels,
                     &IP_LQG_PCI6221_2015a_P.AnalogOutput_InitialValue, &parm);
    }
  }

  {
    int_T is;

    /* InitializeConditions for StateSpace: '<Root>/LQG' */
    for (is = 0; is < 5; is++) {
      IP_LQG_PCI6221_2015a_X.LQG_CSTATE[is] = IP_LQG_PCI6221_2015a_P.LQG_X0;
    }

    /* End of InitializeConditions for StateSpace: '<Root>/LQG' */

    /* S-Function Block: <S4>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = IP_LQG_PCI6221_2015a_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &IP_LQG_PCI6221_2015a_P.EncoderInput1_Channels, NULL, &parm);
    }

    /* S-Function Block: <S6>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = IP_LQG_PCI6221_2015a_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &IP_LQG_PCI6221_2015a_P.EncoderInput_Channels, NULL, &parm);
    }
  }
}

/* Model terminate function */
void IP_LQG_PCI6221_2015a_terminate(void)
{
  /* S-Function Block: <S1>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) IP_LQG_PCI6221_2015a_P.AnalogOutput_RangeMode;
      parm.rangeidx = IP_LQG_PCI6221_2015a_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &IP_LQG_PCI6221_2015a_P.AnalogOutput_Channels,
                     &IP_LQG_PCI6221_2015a_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  IP_LQG_PCI6221_2015a_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  IP_LQG_PCI6221_2015a_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  IP_LQG_PCI6221_2015a_initialize();
}

void MdlTerminate(void)
{
  IP_LQG_PCI6221_2015a_terminate();
}

/* Registration function */
RT_MODEL_IP_LQG_PCI6221_2015a_T *IP_LQG_PCI6221_2015a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  IP_LQG_PCI6221_2015a_P.EncoderInput1_InputFilter = rtInf;
  IP_LQG_PCI6221_2015a_P.EncoderInput_InputFilter = rtInf;
  IP_LQG_PCI6221_2015a_P.EncoderInput1_MaxMissedTicks = rtInf;
  IP_LQG_PCI6221_2015a_P.EncoderInput_MaxMissedTicks = rtInf;

  /* initialize real-time model */
  (void) memset((void *)IP_LQG_PCI6221_2015a_M, 0,
                sizeof(RT_MODEL_IP_LQG_PCI6221_2015a_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&IP_LQG_PCI6221_2015a_M->solverInfo,
                          &IP_LQG_PCI6221_2015a_M->Timing.simTimeStep);
    rtsiSetTPtr(&IP_LQG_PCI6221_2015a_M->solverInfo, &rtmGetTPtr
                (IP_LQG_PCI6221_2015a_M));
    rtsiSetStepSizePtr(&IP_LQG_PCI6221_2015a_M->solverInfo,
                       &IP_LQG_PCI6221_2015a_M->Timing.stepSize0);
    rtsiSetdXPtr(&IP_LQG_PCI6221_2015a_M->solverInfo,
                 &IP_LQG_PCI6221_2015a_M->ModelData.derivs);
    rtsiSetContStatesPtr(&IP_LQG_PCI6221_2015a_M->solverInfo, (real_T **)
                         &IP_LQG_PCI6221_2015a_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&IP_LQG_PCI6221_2015a_M->solverInfo,
      &IP_LQG_PCI6221_2015a_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&IP_LQG_PCI6221_2015a_M->solverInfo,
                          (&rtmGetErrorStatus(IP_LQG_PCI6221_2015a_M)));
    rtsiSetRTModelPtr(&IP_LQG_PCI6221_2015a_M->solverInfo,
                      IP_LQG_PCI6221_2015a_M);
  }

  rtsiSetSimTimeStep(&IP_LQG_PCI6221_2015a_M->solverInfo, MAJOR_TIME_STEP);
  IP_LQG_PCI6221_2015a_M->ModelData.intgData.y =
    IP_LQG_PCI6221_2015a_M->ModelData.odeY;
  IP_LQG_PCI6221_2015a_M->ModelData.intgData.f[0] =
    IP_LQG_PCI6221_2015a_M->ModelData.odeF[0];
  IP_LQG_PCI6221_2015a_M->ModelData.intgData.f[1] =
    IP_LQG_PCI6221_2015a_M->ModelData.odeF[1];
  IP_LQG_PCI6221_2015a_M->ModelData.intgData.f[2] =
    IP_LQG_PCI6221_2015a_M->ModelData.odeF[2];
  IP_LQG_PCI6221_2015a_M->ModelData.contStates = ((real_T *)
    &IP_LQG_PCI6221_2015a_X);
  rtsiSetSolverData(&IP_LQG_PCI6221_2015a_M->solverInfo, (void *)
                    &IP_LQG_PCI6221_2015a_M->ModelData.intgData);
  rtsiSetSolverName(&IP_LQG_PCI6221_2015a_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = IP_LQG_PCI6221_2015a_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    IP_LQG_PCI6221_2015a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    IP_LQG_PCI6221_2015a_M->Timing.sampleTimes =
      (&IP_LQG_PCI6221_2015a_M->Timing.sampleTimesArray[0]);
    IP_LQG_PCI6221_2015a_M->Timing.offsetTimes =
      (&IP_LQG_PCI6221_2015a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    IP_LQG_PCI6221_2015a_M->Timing.sampleTimes[0] = (0.0);
    IP_LQG_PCI6221_2015a_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    IP_LQG_PCI6221_2015a_M->Timing.offsetTimes[0] = (0.0);
    IP_LQG_PCI6221_2015a_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(IP_LQG_PCI6221_2015a_M, &IP_LQG_PCI6221_2015a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = IP_LQG_PCI6221_2015a_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    IP_LQG_PCI6221_2015a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(IP_LQG_PCI6221_2015a_M, 200.0);
  IP_LQG_PCI6221_2015a_M->Timing.stepSize0 = 0.001;
  IP_LQG_PCI6221_2015a_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  IP_LQG_PCI6221_2015a_M->Sizes.checksums[0] = (1584719379U);
  IP_LQG_PCI6221_2015a_M->Sizes.checksums[1] = (2353970816U);
  IP_LQG_PCI6221_2015a_M->Sizes.checksums[2] = (2681559543U);
  IP_LQG_PCI6221_2015a_M->Sizes.checksums[3] = (1772466400U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    IP_LQG_PCI6221_2015a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(IP_LQG_PCI6221_2015a_M->extModeInfo,
      &IP_LQG_PCI6221_2015a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(IP_LQG_PCI6221_2015a_M->extModeInfo,
                        IP_LQG_PCI6221_2015a_M->Sizes.checksums);
    rteiSetTPtr(IP_LQG_PCI6221_2015a_M->extModeInfo, rtmGetTPtr
                (IP_LQG_PCI6221_2015a_M));
  }

  IP_LQG_PCI6221_2015a_M->solverInfoPtr = (&IP_LQG_PCI6221_2015a_M->solverInfo);
  IP_LQG_PCI6221_2015a_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&IP_LQG_PCI6221_2015a_M->solverInfo, 0.001);
  rtsiSetSolverMode(&IP_LQG_PCI6221_2015a_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  IP_LQG_PCI6221_2015a_M->ModelData.blockIO = ((void *) &IP_LQG_PCI6221_2015a_B);
  (void) memset(((void *) &IP_LQG_PCI6221_2015a_B), 0,
                sizeof(B_IP_LQG_PCI6221_2015a_T));

  /* parameters */
  IP_LQG_PCI6221_2015a_M->ModelData.defaultParam = ((real_T *)
    &IP_LQG_PCI6221_2015a_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &IP_LQG_PCI6221_2015a_X;
    IP_LQG_PCI6221_2015a_M->ModelData.contStates = (x);
    (void) memset((void *)&IP_LQG_PCI6221_2015a_X, 0,
                  sizeof(X_IP_LQG_PCI6221_2015a_T));
  }

  /* states (dwork) */
  IP_LQG_PCI6221_2015a_M->ModelData.dwork = ((void *) &IP_LQG_PCI6221_2015a_DW);
  (void) memset((void *)&IP_LQG_PCI6221_2015a_DW, 0,
                sizeof(DW_IP_LQG_PCI6221_2015a_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    IP_LQG_PCI6221_2015a_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  IP_LQG_PCI6221_2015a_M->Sizes.numContStates = (5);/* Number of continuous states */
  IP_LQG_PCI6221_2015a_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  IP_LQG_PCI6221_2015a_M->Sizes.numY = (0);/* Number of model outputs */
  IP_LQG_PCI6221_2015a_M->Sizes.numU = (0);/* Number of model inputs */
  IP_LQG_PCI6221_2015a_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  IP_LQG_PCI6221_2015a_M->Sizes.numSampTimes = (2);/* Number of sample times */
  IP_LQG_PCI6221_2015a_M->Sizes.numBlocks = (45);/* Number of blocks */
  IP_LQG_PCI6221_2015a_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  IP_LQG_PCI6221_2015a_M->Sizes.numBlockPrms = (74);/* Sum of parameter "widths" */
  return IP_LQG_PCI6221_2015a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
