#ifndef RAVEN_CHAINPARAMSSEEDS_H
#define RAVEN_CHAINPARAMSSEEDS_H
/**
 * Each line contains a 16-byte IPv6 address and a port.
 * IPv4 as well as onion addresses are wrapped inside a IPv6 address accordingly.
 */
static SeedSpec6 pnSeed6_main[] = {
    {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x22,0xd6,0xc1,0x7d}, 9617},
    {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x34,0xd3,0xeb,0x6c}, 9617}
};

static SeedSpec6 pnSeed6_test[] = {
    {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x22,0xd6,0xc1,0x7d}, 19617},
    {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0x34,0xd3,0xeb,0x6c}, 19617}
};
#endif // RAVEN_CHAINPARAMSSEEDS_H
