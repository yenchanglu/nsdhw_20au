import Vector2D as vec2d
import pytest as pt
import math


def testInvalidVector():
    with pt.raises(Exception):
        vec2d.getAngle([1],[1,2])

def testZeroLen():
    get_angle = vec2d.getAngle([0,0], [0,1])
    assert math.isclose(get_angle, 0, rel_tol=1e-06)
    get_angle2 = vec2d.getAngle([0,0], [1,0])
    assert math.isclose(get_angle2, 0, rel_tol=1e-06)

def test45Deg():
    get_angle = vec2d.getAngle([1,1], [0,1])
    assert math.isclose(get_angle, math.pi/4, rel_tol=1e-06)

def testRightAngle():
    get_angle = vec2d.getAngle([1,0], [0,1])
    assert math.isclose(get_angle, math.pi/2, rel_tol=1e-06)

