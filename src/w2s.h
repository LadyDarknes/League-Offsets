#pragma once

#ifndef VEC3_DEFINED
#define VEC3_DEFINED
struct Vec3 {
    float x, y, z;
    float dist2d(const Vec3& o) const {
        float dx = x - o.x;
        float dz = z - o.z;
        return sqrtf(dx * dx + dz * dz);
    }
};
#endif

struct CameraData {
    float viewMtx[16];
    float projMtx[16];
    float camPos[3];
    int vpLeft, vpTop, vpRight, vpBottom;
    bool valid = false;
};

struct ScreenCoord {
    float x, y;
    bool onScreen;
};

inline bool W2S(const CameraData& cam, const Vec3& w, ScreenCoord& out) {
    if (!cam.valid) return false;
    // camera world position
    float dx = w.x - cam.camPos[0];
    float dy = w.y - cam.camPos[1];
    float dz = w.z - cam.camPos[2];

    const float* V = cam.viewMtx;
    const float* P = cam.projMtx;

    float vx = dx * V[0] + dy * V[4] + dz * V[8]  + V[12];
    float vy = dx * V[1] + dy * V[5] + dz * V[9]  + V[13];
    float vz = dx * V[2] + dy * V[6] + dz * V[10] + V[14];
    float vw = dx * V[3] + dy * V[7] + dz * V[11] + V[15];
  
    float cx = vx * P[0] + vy * P[4] + vz * P[8]  + vw * P[12];
    float cy = vx * P[1] + vy * P[5] + vz * P[9]  + vw * P[13];
    float cz = vx * P[2] + vy * P[6] + vz * P[10] + vw * P[14];
    float cw = vx * P[3] + vy * P[7] + vz * P[11] + vw * P[15];

    if (cw <= 0.001f) return false;
    float inv = 1.0f / cw;
    float vpW = static_cast<float>(cam.vpRight  - cam.vpLeft);
    float vpH = static_cast<float>(cam.vpBottom - cam.vpTop);

    out.x = (cx * inv + 1.0f) * vpW * 0.5f + static_cast<float>(cam.vpLeft);
    out.y = (1.0f - cy * inv) * vpH * 0.5f + static_cast<float>(cam.vpTop);
    // bounds verification
    out.onScreen = (out.x >= 0.0f && out.x <= static_cast<float>(cam.vpRight) && out.y >= 0.0f && out.y <= static_cast<float>(cam.vpBottom));

    return out.onScreen;
}
