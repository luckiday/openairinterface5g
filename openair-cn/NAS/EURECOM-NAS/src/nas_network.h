/*****************************************************************************
			Eurecom OpenAirInterface 3
			Copyright(c) 2012 Eurecom

Source		nas_network.h

Version		0.1

Date		2012/09/20

Product		NAS stack

Subsystem	NAS main process

Author		Frederic Maurel

Description	NAS procedure functions triggered by the network

*****************************************************************************/
#ifndef __NAS_NETWORK_H__
#define __NAS_NETWORK_H__

/****************************************************************************/
/*********************  G L O B A L    C O N S T A N T S  *******************/
/****************************************************************************/

/****************************************************************************/
/************************  G L O B A L    T Y P E S  ************************/
/****************************************************************************/

/****************************************************************************/
/********************  G L O B A L    V A R I A B L E S  ********************/
/****************************************************************************/

/****************************************************************************/
/******************  E X P O R T E D    F U N C T I O N S  ******************/
/****************************************************************************/

void nas_network_initialize(void);

void nas_network_cleanup(void);

int nas_network_process_data(int command_id, const void* data);

const void* nas_network_get_data(void);

#endif /* __NAS_NETWORK_H__*/
