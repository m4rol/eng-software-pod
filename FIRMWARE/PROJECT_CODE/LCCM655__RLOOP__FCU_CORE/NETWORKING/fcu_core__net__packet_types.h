/*
 * fcu_core__net__packet_types.h
 *
 *  Created on: Dec 9, 2016
 *      Author: Lachlan
 */

#ifndef __NET__PACKET_TYPES_H_
#define __NET__PACKET_TYPES_H_

	/** rLoop UDP network packet types
	* http://confluence.rloop.org/display/SD/Packet+Types
	*/
	typedef enum
	{

		/** null packet type */
		NET_PKT__NONE = 0x000U,

		//////////////////////////////////////////////////////
		//FCU: GENERAL (0x0000)
		//////////////////////////////////////////////////////

		/** Pod stop command */
		NET_PKT__FCU_GEN__POD_STOP_COMMAND = 0x0001U,

		/** Allow us to emulate pod sensor data */
		NET_PKT__FCU_GEN__POD_EMULATION_CONTROL = 0x0002U,

		/** Flight control data streaming */
		NET_PKT__FCU_GEN__STREAMING_CONTROL = 0x0100U,

		//////////////////////////////////////////////////////
		//FCU: ACCEL (0x1000)
		//////////////////////////////////////////////////////

		/** Request from the host to send the Acclelerometer calibration data */
		NET_PKT__FCU_ACCEL__REQUEST_CAL_DATA = 0x1000U,

		/** Transmit the accel calibration data to the host */
		NET_PKT__FCU_ACCEL__TX_CAL_DATA = 0x1001U,

		/** request a full data stream from our devices */
		NET_PKT__FCU_ACCEL__REQUEST_FULL_DATA = 0x1002U,

		/** Transmit the full available accel data to the host */
		NET_PKT__FCU_ACCEL__TX_FULL_DATA = 0x1003U,

		/** enter auto calibration mode */
		NET_PKT__FCU_ACCEL__AUTO_CALIBRATE = 0x1004U,

		/** Fine adjustment on Any */
		NET_PKT__FCU_ACCEL__FINE_ZERO_ADJUSTMENT = 0x1005U,


		//////////////////////////////////////////////////////
		//FCU: LASER OPTONCDT (0x1100)
		//////////////////////////////////////////////////////

		/** Request from the host to send the laser data */
		NET_PKT__LASER_OPTO__REQUEST_LASER_DATA = 0x1100U,

		/** FCU to Host, return laser data */
		NET_PKT__LASER_OPTO__TX_LASER_DATA = 0x1101U,



		//////////////////////////////////////////////////////
		//FCU: LASER DISTANCE (0x1200)
		//////////////////////////////////////////////////////

		/** Request from the host to send the laser data */
		NET_PKT__LASER_DIST__REQUEST_LASER_DATA = 0x1200U,

		/** FCU to Host, return laser data */
		NET_PKT__LASER_DIST__TX_LASER_DATA = 0x1201U,



		//////////////////////////////////////////////////////
		//FCU: LASER CONTRAST (0x1300)
		//////////////////////////////////////////////////////

		/** Request from the host to send the laser data */
		NET_PKT__LASER_CONT__REQUEST_LASER_DATA = 0x1300U,

		/** FCU to Host, return laser data */
		NET_PKT__LASER_CONT__TX_LASER_DATA = 0x1301U,


		//////////////////////////////////////////////////////
		//FCU: BRAKES (0x1400)
		//////////////////////////////////////////////////////

		/** Permit brake development mode */
		NET_PKT__FCU_BRAKES__ENABLE_DEV_MODE = 0x1400U,

		/** Perform a raw motor move */
		NET_PKT__FCU_BRAKES__MOVE_MOTOR_RAW = 0x1401U,

		//////////////////////////////////////////////////////
		//POWER: GENERAL (0x3000)
		//////////////////////////////////////////////////////

		/** Pod safe command */
		NET_PKT__PWR_GEN__POD_SAFE_COMMAND = 0x3000U,

		/** Allow us to emulate pod sensor data */
		NET_PKT__PWR_GEN__POD_EMULATION_CONTROL = 0x3001U,

		/** Power Node data streaming */
		NET_PKT__PWR_GEN__STREAMING_CONTROL = 0x3010U,


		//////////////////////////////////////////////////////
		//POWER: TEMPERATURE SYSTEM (0x3200)
		//////////////////////////////////////////////////////

		/** Request a temperature packet */
		NET_PKT__PWR_TEMP__REQ_CURRENT_TEMPS = 0x3200U,

		/** Send an entire temperature sensor packet */
		NET_PKT__PWR_TEMP__TX_CURRENT_TEMPS = 0x3201U,

		/** Host wants sensor loc data */
		NET_PKT__PWR_TEMP__REQ_SENSOR_LOCATION = 0x3202U,

		/** Send the location data */
		NET_PKT__PWR_TEMP__TX_SENSOR_LOCATION_DATA = 0x3203U,

		/** Request a ROMID based on an index */
		NET_PKT__PWR_TEMP__REQ_ROMID_INDEX = 0x3204U,

		/** Send the ROMID based on an index */
		NET_PKT__PWR_TEMP__TX_ROMID_INDEX = 0x3205U,

		/** Set the ROMID by sensor index */
		NET_PKT__PWR_TEMP__SET_ROMID_INDEX = 0x3206U,

		/** Set the User Data by Sensor Index*/
		NET_PKT__PWR_TEMP__SET_USERDATA_INDEX = 0x3207U,



		//////////////////////////////////////////////////////
		//XILINX HYPERLOOP SIMULATION (0x5000)
		//////////////////////////////////////////////////////

		/** simulation control on the ML507 board */
		NET_PKT__XILINX_SIM__SIMULATION_CONTROL = 0x5000U


	}E_NET__PACKET_T;




#endif /* __NET__PACKET_TYPES_H_ */
