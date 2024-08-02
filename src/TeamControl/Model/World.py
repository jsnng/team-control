from TeamControl.Model.ssl_vision_wrapper_py import SSL_WrapperPacket
from collections import deque

class World:
    """representation of the state of the football match

    Attributes
    ----------
    ssl_detection_frames : deque
        deque of `ssl_vision_wrapper_py.SSL_DetectionFrame`
    ssl_geometry_data: deque
        deque of `ssl_vision_wrapper_py.SSL_GeometeryData`

    Properties
    ----------
    is_yellow: bool
        True if the team colour is `yellow`. False if the team colour is `blue`
    is_positive_half: bool
        True if the team is on the positive `x` side of the field.
    
    Methods
    -------
    update(**kwargs)
    get_balls()
    get_robots_yellow()
    get_robots_blue()

    """

    def __init__(self, is_yellow: bool, is_positive_half: bool, maxlen: int=5) -> object:
        """creates a new `World` object

        Parameters
        ----------
        is_yellow: bool
            True if the team colour is `yellow`. False if the team colour is `blue`
        is_positive: bool
            True if the team is on the positive `x` side of the field.
        maxlen: int, default=5
            max size of `ssl_detection_frames` and `ssl_geometry_data` deques
        """
        self.ssl_detection_frames = deque(maxlen=maxlen)
        self.ssl_geometry_data = deque(maxlen=maxlen)

        self._is_yellow = is_yellow
        self._is_positive_half = is_positive_half

    @property
    def is_yellow(self) -> bool:
        return self._is_yellow
    
    @property
    def is_positive_half(self) -> bool:
        return self._is_positive_half

    def update(self, **kwargs) -> None:
        """updates the world

        Arguments
        ---------
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_wrapper.proto` for 
            the structure of `SSL_WrapperPacket`
        """
        new_frame = SSL_WrapperPacket(**kwargs)
        if new_frame.is_detection_frame:
            self.ssl_detection_frames.append(new_frame)
            
        if new_frame.is_geometry_data:
            self.ssl_geometry_data.append(new_frame)

    def get_balls(self) -> list:
        frames = list(self.ssl_detection_frames)

    def get_yellow_robots(self) -> list:
        frames = list(self.ssl_detection_frames)

    def get_blue_robots(self) -> list:
        frames = list(self.ssl_detection_frames)

