// MESSAGE ROLL_SIMULATION PACKING

#define MAVLINK_MSG_ID_ROLL_SIMULATION 154

typedef struct __mavlink_roll_simulation_t
{
 int16_t roll; ///< roll value in degree
} mavlink_roll_simulation_t;

#define MAVLINK_MSG_ID_ROLL_SIMULATION_LEN 2
#define MAVLINK_MSG_ID_154_LEN 2



#define MAVLINK_MESSAGE_INFO_ROLL_SIMULATION { \
	"ROLL_SIMULATION", \
	1, \
	{  { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_roll_simulation_t, roll) }, \
         } \
}


/**
 * @brief Pack a roll_simulation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param roll roll value in degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_roll_simulation_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t roll)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_int16_t(buf, 0, roll);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_roll_simulation_t packet;
	packet.roll = roll;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_ROLL_SIMULATION;
	return mavlink_finalize_message(msg, system_id, component_id, 2, 170);
}

/**
 * @brief Pack a roll_simulation message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param roll roll value in degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_roll_simulation_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t roll)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_int16_t(buf, 0, roll);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_roll_simulation_t packet;
	packet.roll = roll;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_ROLL_SIMULATION;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 170);
}

/**
 * @brief Encode a roll_simulation struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param roll_simulation C-struct to read the message contents from
 */
static __inline uint16_t mavlink_msg_roll_simulation_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_roll_simulation_t* roll_simulation)
{
	return mavlink_msg_roll_simulation_pack(system_id, component_id, msg, roll_simulation->roll);
}

/**
 * @brief Send a roll_simulation message
 * @param chan MAVLink channel to send the message
 *
 * @param roll roll value in degree
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static __inline void mavlink_msg_roll_simulation_send(mavlink_channel_t chan, int16_t roll)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_int16_t(buf, 0, roll);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROLL_SIMULATION, buf, 2, 170);
#else
	mavlink_roll_simulation_t packet;
	packet.roll = roll;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ROLL_SIMULATION, (const char *)&packet, 2, 170);
#endif
}

#endif

// MESSAGE ROLL_SIMULATION UNPACKING


/**
 * @brief Get field roll from roll_simulation message
 *
 * @return roll value in degree
 */
static __inline int16_t mavlink_msg_roll_simulation_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Decode a roll_simulation message into a struct
 *
 * @param msg The message to decode
 * @param roll_simulation C-struct to decode the message contents into
 */
static __inline void mavlink_msg_roll_simulation_decode(const mavlink_message_t* msg, mavlink_roll_simulation_t* roll_simulation)
{
#if MAVLINK_NEED_BYTE_SWAP
	roll_simulation->roll = mavlink_msg_roll_simulation_get_roll(msg);
#else
	memcpy(roll_simulation, _MAV_PAYLOAD(msg), 2);
#endif
}
