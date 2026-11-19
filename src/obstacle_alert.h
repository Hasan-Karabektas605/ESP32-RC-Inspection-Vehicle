#ifndef OBSTACLE_ALERT_H
#define OBSTACLE_ALERT_H

enum class ObstacleLevel {
    UNKNOWN,
    SAFE,
    WARNING,
    DANGER,
    CRITICAL
};

class ObstacleAlert {
public:
    ObstacleLevel evaluate(float distance) const {
        if (!(distance >= 2.0f && distance <= 400.0f))
            return ObstacleLevel::UNKNOWN;

        if (distance <= 10.0f)
            return ObstacleLevel::CRITICAL;

        if (distance <= 20.0f)
            return ObstacleLevel::DANGER;

        if (distance <= 40.0f)
            return ObstacleLevel::WARNING;

        return ObstacleLevel::SAFE;
    }

    const char* getMessage(ObstacleLevel level) const {
        switch (level) {
            case ObstacleLevel::CRITICAL:
                return "STOP IMMEDIATELY";
            case ObstacleLevel::DANGER:
                return "Obstacle very close";
            case ObstacleLevel::WARNING:
                return "Obstacle approaching";
            case ObstacleLevel::SAFE:
                return "Path clear";
            default:
                return "Invalid sensor reading";
        }
    }
};

#endif
