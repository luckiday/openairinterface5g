#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#include "TLVEncoder.h"
#include "TLVDecoder.h"
#include "RadioPriority.h"

int decode_radio_priority(RadioPriority *radiopriority, uint8_t iei, uint8_t *buffer, uint32_t len)
{
    int decoded = 0;
    CHECK_PDU_POINTER_AND_LENGTH_DECODER(buffer, RADIO_PRIORITY_MINIMUM_LENGTH, len);
    if (iei > 0)
    {
        CHECK_IEI_DECODER((*buffer & 0xf0), iei);
    }
    *radiopriority = *buffer & 0x7;
    decoded++;
#if defined (NAS_DEBUG)
    dump_radio_priority_xml(radiopriority, iei);
#endif
    return decoded;
}

int decode_u8_radio_priority(RadioPriority *radiopriority, uint8_t iei, uint8_t value, uint32_t len)
{
    int decoded = 0;
    uint8_t *buffer = &value;
    *radiopriority = *buffer & 0x7;
    decoded++;
#if defined (NAS_DEBUG)
    dump_radio_priority_xml(radiopriority, iei);
#endif
    return decoded;
}

int encode_radio_priority(RadioPriority *radiopriority, uint8_t iei, uint8_t *buffer, uint32_t len)
{
    uint8_t encoded = 0;
    /* Checking length and pointer */
    CHECK_PDU_POINTER_AND_LENGTH_ENCODER(buffer, RADIO_PRIORITY_MINIMUM_LENGTH, len);
#if defined (NAS_DEBUG)
    dump_radio_priority_xml(radiopriority, iei);
#endif
    *(buffer + encoded) = 0x00 | (iei & 0xf0) |
    (*radiopriority & 0x7);
    encoded++;
    return encoded;
}

uint8_t encode_u8_radio_priority(RadioPriority *radiopriority)
{
    uint8_t bufferReturn;
    uint8_t *buffer = &bufferReturn;
    uint8_t encoded = 0;
    uint8_t iei = 0;
    dump_radio_priority_xml(radiopriority, 0);
    *(buffer + encoded) = 0x00 | (iei & 0xf0) |
    (*radiopriority & 0x7);
    encoded++;

    return bufferReturn;
}

void dump_radio_priority_xml(RadioPriority *radiopriority, uint8_t iei)
{
    printf("<Radio Priority>\n");
    if (iei > 0)
        /* Don't display IEI if = 0 */
        printf("    <IEI>0x%X</IEI>\n", iei);
    printf("    <Radio priority level value>%u</Radio priority level value>\n", *radiopriority);
    printf("</Radio Priority>\n");
}

