/**
 * @file		FCU__LASER_OPTO__FILTERING.C
 * @brief		OptoNCDT laser filtering system
 * @author		Lachlan Grogan, Marek Gutt-Mostowy
 * @copyright	rLoop Inc.
 */
/**
 * @addtogroup RLOOP
 * @{ */
/**
 * @addtogroup FCU
 * @ingroup RLOOP
 * @{ */
/**
 * @addtogroup FCU__LASER_OPTO__FILTERING
 * @ingroup FCU
 * @{ */

//implements an exponential moving average filter for the optoNCDT distance sensors

//see https://github.com/rLoopTeam/eng-software-pod/blob/development/TEST_DATA/2016_11_17/filter_laser_data.py for Python implementation

//results available under the following confluence page http://confluence.rloop.org/display/SD/Filtering+of+the+Distance+Sensors+data+for+Roll%2C+Pitch%2C+Yaw%2C+HE+Height%2C+Lat+Position

#include "../fcu_core.h"

#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U
#if C_LOCALDEF__LCCM655__ENABLE_LASER_OPTONCDT == 1U

//the structure
extern struct _strFCU sFCU;

	//new data source here:
	//sFCU.sLaserOpto.sOptoLaser[(Luint8)eLaser].f32Distance
	//update this value
	//sFCU.sLaserOpto.sOptoLaser[u8Counter].sFiltered.f32FilteredValue

void vFCU_LASEROPTO_FILT__FilterPacket(E_FCU__LASER_OPTO__INDEX_T eLaser)
{

Lfloat32 f32FilterAlpha = 0.008F;
Lfloat32 f32NewSampleInfluence = 0.0F;
Lfloat32 f32OldSampleInfluence = 0.0F
Lfloat32 f32MaxRange = 50.0F;

	//exponential moving average filter

	//reject values above 50 as this is what sensor indicates in case out of range
	if (sFCU.sLaserOpto.sOptoLaser[(Luint8)eLaser].f32Distance < f32MaxRange) {

	//  @see http://dsp.stackexchange.com/questions/20333/how-to-implement-a-moving-average-in-c-without-a-buffer

	//Calculate the old sample influence
	f32NewSampleInfluence = f32FilterAlpha * sFCU.sLaserOpto.sOptoLaser[(Luint8)eLaser].f32Distance;
	//Calculatre the new sample influence
	f32OldSampleInfluence = (1 - f32FilterAlpha) * sFCU.sLaserOpto.sOptoLaser[(Luint8)eLaser].sFiltered.f32PreviousValue;
	//Update the current value
	sFCU.sLaserOpto.sOptoLaser[(Luint8)eLaser].sFiltered.f32FilteredValue = f32OldSampleInfluence + f32NewSampleInfluence;

	// Store old sample 
 	sFCU.sLaserOpto.sOptoLaser[(Luint8)eLaser].sFiltered.f32PreviousValue = sFCU.sLaserOpto.sOptoLaser[(Luint8)eLaser].f32Distance;
	
	}

}


#endif //C_LOCALDEF__LCCM655__ENABLE_LASER_OPTONCDT

#endif //#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U
//safetys
#ifndef C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE
	#error
#endif
/** @} */
/** @} */
/** @} */
