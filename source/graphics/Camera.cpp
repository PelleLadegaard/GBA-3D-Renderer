#include "../../include/graphics/Camera.h"

#include "../../include/utility/math.h"

void Camera::move(int distance, int direction){
    pos.x += cosLut(distance, direction);
	pos.y += sinLut(distance, direction);
}

void Camera::rotate(int direction){
    dir += direction;
    invdir -= direction;
}