#ifndef S6A_MESSAGES_TYPES_H_
#define S6A_MESSAGES_TYPES_H_

typedef struct {
#define SKIP_SUBSRIBER_DATA (0x1)
    unsigned skip_subsriber_data:1;
#define INITIAL_ATTACH      (0x1)
    unsigned initial_attach:1;

    char       imsi[IMSI_DIGITS_MAX];
    uint8_t    imsi_length;
    plmn_t     visited_plmn;
    rat_type_t rat_type;
} s6a_update_location_req_t;

typedef struct {
    char    imsi[IMSI_DIGITS_MAX];
    uint8_t imsi_length;

    /* Result of the update location request procedure */
    s6a_result_t        result;
    subscription_data_t subscription_data;
} s6a_update_location_ans_t;

typedef struct {
    char    imsi[IMSI_DIGITS_MAX];
    uint8_t imsi_length;
    plmn_t  visited_plmn;
    /* Number of vectors to retrieve from HSS, should be equal to one */
    uint8_t nb_of_vectors;
} s6a_auth_info_req_t;

typedef struct {
    char       imsi[IMSI_DIGITS_MAX];
    uint8_t    imsi_length;

    /* Result of the authentication information procedure */
    s6a_result_t result;
    /* Authentication info containing the vector(s) */
    authentication_info_t auth_info;
} s6a_auth_info_ans_t;

#endif /* S6A_MESSAGES_TYPES_H_ */
