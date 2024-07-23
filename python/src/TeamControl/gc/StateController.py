from TeamControl.gc.GameController import _tc_gc_state_controller
import numpy as np
import math

from TeamControl.Model.Frame import Frame, Robot
import logging

log = logging.getLogger()
log.setLevel(logging.NOTSET)

class Vector:
    def __init__(self, x=0, y=0, o=0, m=0):
        self._x = x
        self._y = y
        self._o = o
        self._m = m

    @property
    def x(self):
        return self._x
    
    @x.setter
    def x(self, x):
        self._x = x

    @property
    def y(self):
        return self._y
    
    @y.setter
    def y(self, y):
        self._y = y

    @property
    def o(self):
        return self._o
    
    @o.setter
    def o(self, o):
        self._o = o

    @property
    def m(self):
        return self._o
    
    @m.setter
    def m(self, m):
        self._m = m

    def translate(self, other):
        translation = np.array([
            [1, 0, other.x],
            [0, 1, other.y],
            [0, 0, 1],
        ])

        us = np.array([self.x, self.y, 1])
        x, y, _ = np.matmul(translation, us)
        return Vector(x, y, self.o, self.m)
    

    def rotation(self, phi):
        rotation = np.array([
            [np.cos(phi), -np.sin(phi), 0],
            [np.sin(phi), np.cos(phi), 0],
            [0, 0, 1],
        ])
        us = np.array([self.x, self.y, 1])
        x, y, _ = np.matmul(rotation, us)
        return Vector(x, y, self.o, self.m)
    
    def scaling(self, factor_x, factor_y):
        scaling = np.array([
            [factor_x, 0, 0],
            [0, factor_y, 0],
            [0, 0, 1],
        ])

        us = np.array([self.x, self.y, 1])
        x, y, _ = np.matmul(scaling, us)
        return Vector(x, y, self.o, self.m)

class Motion:
    @staticmethod
    def _to_point(origin, dest, threshold):

        max_vel = 150
        x0 = origin.x
        y0 = origin.y

        origin = origin.translate(dest)

        x1 = dest.x
        y1 = dest.y

        dy = y1 - y0
        dx = x1 - x0

        angle = math.atan2(dy, dx)

        vx = max_vel * np.cos(angle)
        vy = max_vel * np.sin(angle)

        if  np.sqrt(dy**2 + dx**2) < threshold:
            vx = 0
            vy = 0

        return vx, vy
    
    def _fix_orientation(origin, dest):
        ...

class gc_state_controller(_tc_gc_state_controller):
    def __init__(self, world_model, new_state_q, send_to_robot_q):
        super().__init__(world_model, new_state_q, send_to_robot_q)

    def _halt(self):
        ...

    def _stop(self):
        ...
        
    def _prepare_kickoff_yellow(self):
        ...

    def _prepare_kickoff_blue(self):
        ...
       
    def _normal_start(self):
        ...

    def _force_start(self):
        ...
    
    def _prepare_kickoff_yellow(self):
        ...

    def _prepare_kickoff_blue(self):
        ...

    def _prepare_penalty_yellow(self):
        ...

    def _prepare_penatly_blue(self):
        ...
    
    def _direct_free_yellow(self):
        ...

    def _direct_free_blue(self):
        ...

    def _indirect_free_yellow(self):
        ...

    def _indirect_free_blue(self):
        ...

    def _timeout_yellow(self):
        ...

    def _timeout_blue(self):
        ...
    
    def _goal_yellow(self):
        ...

    def _goal_blue(self):
        ...

    def _ball_placement_yellow(self):
        ...

    def _ball_placement_blue(self):
        ...

    def _unknown_command(self):
        ...
        
    def _run(self):
        ...

        
