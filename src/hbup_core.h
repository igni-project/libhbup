/* hbup_core.h
 * The HBUP standard itself */

#ifndef _LIBHBUP_HBUP_CORE_H
#define _LIBHBUP_HBUP_CORE_H 1

#include <stdint.h>
#include <hbup_preproc.h>

/* Version of Hitbox Update Protocol used by library
 * Current version: v1.0 */
#define HBUP_VERSION 0

/* Error codes */
typedef uint8_t hbup_err_code;
enum {
	/* Invalid protocol version
	 * If a client attempts to select an unsupported HBUP version when
	 * configuring its connection, the client shall receive this error. */
	HBUP_ERROR_INVALID_PROTOCOL_VERSION = 0,

	/* Hitbox not found
	 * If a request is to search for a hitbox via ID, but no hitbox matching
	 * the provided ID is found, a ‘hitbox not found’ error shall occur. */
	HBUP_ERROR_HITBOX_NOT_FOUND,

	/* ID already taken
	 * This error shall occur when attempting to create a hitbox with an ID
	 * already in use by another hitbox. */
	HBUP_ERROR_ID_ALREADY_TAKEN,

	/* Invalid opcode
	 * If an incoming request has an opcode unsupported by this protocol,
	 * the server shall respond with an ‘invalid opcode’ error. */
	HBUP_ERROR_INVALID_OPCODE
};

/* Request opcodes
 * All requests are preceded by an opcode. */
typedef uint8_t hbup_req_opcode;
enum {
	/* Configure connection */
	HBUP_REQ_OPCODE_CONFIGURE_CONNECTION = 0,

	/* Create hitbox */
	HBUP_REQ_OPCODE_HITBOX_CREATE,

	/* Set hitbox size */
	HBUP_REQ_OPCODE_HITBOX_SET_SIZE,

	/* Set hitbox location */
	HBUP_REQ_OPCODE_HITBOX_SET_LOCATION,

	/* Set hitbox rotation */
	HBUP_REQ_OPCODE_HITBOX_SET_ROTATION,

	/* Destroy hitbox */
	HBUP_REQ_OPCODE_HITBOX_DESTROY,
	
	/* Cast point */
	HBUP_REQ_CAST_POINT,

	/* Cast ray */
	HBUP_REQ_CAST_RAY
};

/* Response opcodes
 * All responses are preceded by an opcode */
typedef uint8_t hbup_res_opcode;
enum {
	/* Error */
	HBUP_RES_ERROR = 0,

	/* Point hit */
	HBUP_RES_POINT_HIT,

	/* Ray hit */
	HBUP_RES_RAY_HIT
}

/* Responses */

/* Error */
PACK__ typedef struct hbup_res_error_t {
	hbup_req_opcode req_opcode;
	hbup_err_code err_code;
} hbup_res_error __PACK;

/* Point hit */
PACK__ typedef struct hbup_res_point_hit_t {
	int32_t point_id;
} hbup_res_point_hit __PACK;

/* Ray hit */
PACK__ typedef struct hbup_res_ray_hit_t {
	int32_t ray_id;
} hbup_res_ray_hit __PACK;

/* Requests */

/* Configure connection */
PACK__ typedef struct hbup_req_configure_connection_t {
	int32_t version;
} hbup_req_configure_connection __PACK;

/* Create hitbox */
PACK__ typedef struct hbup_req_hitbox_create_t {
	int32_t hitbox_id;
} hbup_req_hitbox_create __PACK;

/* Set hitbox size */
PACK__ typedef struct hbup_req_hitbox_set_size_t {
	int32_t hitbox_id;
	float x;
	float y;
	float z;
} hbup_req_hitbox_set_size __PACK;

/* Set hitbox location */
PACK__ typedef struct hbup_req_hitbox_set_location_t {
	int32_t hitbox_id;
	float x;
	float y;
	float z;
} hbup_req_hitbox_set_location __PACK;

/* Set hitbox rotation */
PACK__ typedef struct hbup_req_hitbox_set_rotation_t {
	int32_t hitbox_id;
	float x;
	float y;
	float z;
} hbup_req_hitbox_set_rotation __PACK;

/* Destroy hitbox */
PACK__ typedef struct hbup_req_hitbox_destroy_t {
	int32_t hitbox_id;
} hbup_req_hitbox_destroy __PACK;

/* Cast point */
PACK__ typedef struct hbup_req_cast_point_t {
	int32_t point_id;
	float x_origin;
	float y_origin;
	float z_origin;
} hbup_req_cast_point __PACK;

/* Cast ray */
PACK__ typedef struct hbup_req_cast_ray_t {
	int32_t ray_id;
	float x_location;
	float y_location;
	float z_location;
	float x_vector;
	float y_vector;
	float z_vector;
} hbup_req_cast_ray __PACK;

#endif

