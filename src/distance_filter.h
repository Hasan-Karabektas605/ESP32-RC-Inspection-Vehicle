#ifndef DISTANCE_FILTER_H
#define DISTANCE_FILTER_H

class DistanceFilter {
private:
    float samples[3] = {};
    int index = 0;
    int count = 0;

public:
    float update(float distance) {
        // Reject invalid sensor readings
        if (!(distance >= 2.0f && distance <= 400.0f))
            return -1.0f;

        samples[index] = distance;
        index = (index + 1) % 3;

        if (count < 3)
            count++;

        if (count < 3)
            return distance;

        float a = samples[0];
        float b = samples[1];
        float c = samples[2];

        // Median filtering
        if ((a <= b && b <= c) ||
            (c <= b && b <= a))
            return b;

        if ((b <= a && a <= c) ||
            (c <= a && a <= b))
            return a;

        return c;
    }
};

#endif
