/* Copyright 2018 Streampunk Media Ltd.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef GRANDIOSE_RECEIVE_H
#define GRANDIOSE_RECEIVE_H

#include "node_api.h"
#include "grandiose_util.h"

napi_value receive(napi_env env, napi_callback_info info);
napi_value videoReceive(napi_env env, napi_callback_info info);

struct receiveCarrier : carrier {
  NDIlib_source_t* source;
  NDIlib_recv_color_format_e colorFormat = NDIlib_recv_color_format_fastest;
  NDIlib_recv_bandwidth_e bandwidth = NDIlib_recv_bandwidth_highest;
  bool allowVideoFields = true;
  char* name = nullptr;
  NDIlib_recv_instance_t recv;
  ~receiveCarrier() {
    free(name);
    delete source;
  }
};

struct videoCarrier : carrier {
  uint32_t wait = 10000;
  NDIlib_recv_instance_t recv;
  NDIlib_video_frame_v2_t videoFrame;
  ~videoCarrier() {}
};

struct audioCarrier : carrier {
  uint32_t wait = 10000;
  NDIlib_recv_instance_t recv;
  ~audioCarrier() {}
};

struct metadataCarrier : carrier {
  uint32_t wait = 10000;
  NDIlib_recv_instance_t recv;
  ~metadataCarrier() {}
};

struct dataCarrier : carrier {
  uint32_t wait = 10000;
  NDIlib_recv_instance_t recv;
  ~dataCarrier() {}
};

#endif /* GRANDIOSE_RECEIVE_H */