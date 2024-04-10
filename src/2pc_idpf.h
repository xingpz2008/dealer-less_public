//
// Created by  邢鹏志 on 2023/1/31.
//
#pragma once
#include <array>
#include <vector>
#include <utility>
#include <cryptoTools/Common/Defines.h>
#include <cryptoTools/Crypto/AES.h>
#include <cryptoTools/Crypto/PRNG.h>
#include <cryptoTools/gsl/span>
#include <cmath>
#include "group_element.h"
#include "keypack.h"
#include "comms.h"
#include "utils.h"
#include "api.h"
#include "2pcwrapper.h"

using namespace osuCrypto;


// extern uint64_t aes_evals_count;



inline u8 lsb(const block &b)
{
    return _mm_cvtsi128_si64x(b) & 1;
}

void two_pc_convert(int bitsize, block *b, uint64_t *out, block* out_s) __attribute__((optimize("O0")));

DPFKeyPack keyGenDPF(int party_id, int Bin, int Bout,
                     GroupElement idx, GroupElement payload, bool masked = true) __attribute__((optimize("O0")));

DPFKeyPack keyGeniDPF(int party_id, int Bin, int Bout,
                      GroupElement idx, GroupElement* payload, bool call_from_DCF = false, bool masked = true) __attribute__((optimize("O0")));

DPFKeyPack keyGeniDPF(int party_id, int Bin, int Bout,
                      u8* idx, GroupElement* payload, bool call_from_DCF = false, bool masked = false) __attribute__((optimize("O0")));

void evalDPF(int party, GroupElement *res, GroupElement idx, const DPFKeyPack &key, bool masked = true) __attribute__((optimize("O0")));
void evaliDPF(int party, GroupElement *res, GroupElement idx, const DPFKeyPack &key, bool masked = true) __attribute__((optimize("O0")));

// Batched evaluation with constant rounds, masked
void evalDPF(int party, GroupElement *res, GroupElement *idx, DPFKeyPack *keyList, int size, int max_bitsize) __attribute__((optimize("O0")));

void evalAll(int party, GroupElement* res, DPFKeyPack key, int length) __attribute__((optimize("O0")));