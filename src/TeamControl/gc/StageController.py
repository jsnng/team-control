from TeamControl.gc.GameController import tc
import logging
from TeamControl.gc.StateController import gc_state_controller

log = logging.getLogger()
log.setLevel(logging.NOTSET)

class StageController(tc):
    def __init__(self, namespace, new_state_q, send_to_robot_q):
        super().__init__(namespace, new_state_q, send_to_robot_q)

        self._tc_gc_state_controller = gc_state_controller(self.world_model, new_state_q, send_to_robot_q)

    def _normal_first_half_pre(self):
        ...

    def _normal_first_half(self):
        ...

    def _normal_half_time(self):
        ...

    def _normal_second_half_pre(self):
        ...

    def _normal_second_half(self):
        ...

    def _extra_time_break(self):
        ...

    def _extra_first_half_pre(self):
        ...

    def _extra_first_half(self):
        ...

    def _extra_half_time(self):
        ...

    def _extra_second_half_pre(self):
        ...

    def _extra_second_half(self):
        ...

    def _penalty_shootout_break(self):
        ...

    def _penalty_shootout(self):
        ...

    def _post_game(self):
        ...