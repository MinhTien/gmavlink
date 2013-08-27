// MESSAGE IMU_CALIB_STATUS PACKING

#define MAVLINK_MSG_ID_IMU_CALIB_STATUS 155

typedef struct __mavlink_imu_calib_status_t
{
 uint8_t calib_status; ///< imu calib status
} mavlink_imu_calib_status_t;

#define MAVLINK_MSG_ID_IMU_CALIB_STATUS_LEN 1
#define MAVLINK_MSG_ID_155_LEN 1



#define MAVLINK_MESSAGE_INFO_IMU_CALIB_STATUS { \
	"IMU_CALIB_STATUS", \
	1, \
	{  { "calib_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_imu_calib_status_t, calib_status) }, \
         } \
}


/**
 * @brief Pack a imu_calib_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param calib_status imu calib status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_imu_calib_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t calib_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, calib_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_imu_calib_status_t packet;
	packet.calib_status = calib_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_CALIB_STATUS;
	return mavlink_finalize_message(msg, system_id, component_id, 1, 23);
}

/**
 * @brief Pack a imu_calib_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param calib_status imu calib status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_imu_calib_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t calib_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, calib_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 1);
#else
	mavlink_imu_calib_status_t packet;
	packet.calib_status = calib_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 1);
#endif

	msg->msgid = MAVLINK_MSG_ID_IMU_CALIB_STATUS;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 1, 23);
}

/**
 * @brief Encode a imu_calib_status struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param imu_calib_status C-struct to read the message contents from
 */
static __inline uint16_t mavlink_msg_imu_calib_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_imu_calib_status_t* imu_calib_status)
{
	return mavlink_msg_imu_calib_status_pack(system_id, component_id, msg, imu_calib_status->calib_status);
}

/**
 * @brief Send a imu_calib_status message
 * @param chan MAVLink channel to send the message
 *
 * @param calib_status imu calib status
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static __inline void mavlink_msg_imu_calib_status_send(mavlink_channel_t chan, uint8_t calib_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[1];
	_mav_put_uint8_t(buf, 0, calib_status);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CALIB_STATUS, buf, 1, 23);
#else
	mavlink_imu_calib_status_t packet;
	packet.calib_status = calib_status;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IMU_CALIB_STATUS, (const char *)&packet, 1, 23);
#endif
}

#endif

// MESSAGE IMU_CALIB_STATUS UNPACKING


/**
 * @brief Get field calib_status from imu_calib_status message
 *
 * @return imu calib status
 */
static __inline uint8_t mavlink_msg_imu_calib_status_get_calib_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a imu_calib_status message into a struct
 *
 * @param msg The message to decode
 * @param imu_calib_status C-struct to decode the message contents into
 */
static __inline void mavlink_msg_imu_calib_status_decode(const mavlink_message_t* msg, mavlink_imu_calib_status_t* imu_calib_status)
{
#if MAVLINK_NEED_BYTE_SWAP
	imu_calib_status->calib_status = mavlink_msg_imu_calib_status_get_calib_status(msg);
#else
	memcpy(imu_calib_status, _MAV_PAYLOAD(msg), 1);
#endif
}
