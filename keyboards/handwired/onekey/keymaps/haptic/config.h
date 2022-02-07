#pragma once

#define FB_ERM_LRA 1
#define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* Please refer to your datasheet for the optimal setting for your specific motor. */
#define RATED_VOLTAGE 2
#define V_PEAK 2.8
#define V_RMS 2.0
#define F_LRA 150 /* resonance freq */
#define DRV_GREETING transition_rampup_long_smooth1
