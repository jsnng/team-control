import enum
from enum import auto
import logging

log = logging.getLogger()
log.setLevel(logging.NOTSET)

class SSL_FieldShapeType(enum.IntEnum):
    Undefined = auto()
    CenterCircle = auto()
    TopTouchLine = auto()
    BottomTouchLine = auto()
    LeftGoalLine = auto()
    RightGoalLine = auto()
    HalfwayLine = auto()
    CenterLine = auto()
    LeftPenaltyStretch = auto()
    RightPenaltyStretch = auto()
    LeftFieldLeftPenaltyStretch = auto()
    LeftFieldRightPenaltyStretch = auto()
    RightFieldLeftPenaltyStretch = auto()
    RightFieldRightPenaltyStretch = auto()

class Vector2f:
    """re-implementation of `ssl_vision_geometry_pb2.Vector2f`

    Properties
    ----------
    x, y : float
        x and y axis distance (mm) from the origin (center point of the field)
    """

    def __init__(self, **kwargs) -> object:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `Vector2f`
        """
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def x(self):
        return self._x

    @x.setter
    def x(self, x):
        if not isinstance(x, float):
            log.error(f'parameter `x` is not an object of type `{float}`')
        self._x = x

    @property
    def y(self):
        return self._y

    @y.setter
    def y(self, y):
        if not isinstance(y, float):
            log.error(f'parameter `y` is not an object of type `{float}`')
        self._y = y

class SSL_FieldLineSegment:
    def __init__(self, **kwargs) -> object:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_FieldLineSegment`
        """
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, name):
        if not isinstance(name, str):
            log.error(f'parameter `name` is not an object of type `{str}`')
        self._name = name

    @property
    def p1(self):
        return self._p1

    @p1.setter
    def p1(self, p1):
        if not isinstance(p1, Vector2f):
            log.error(f'parameter `p1` is not an object of type `{Vector2f}`')
        self._p1 = p1

    @property
    def p2(self):
        return self._p2

    @p2.setter
    def p2(self, p2):
        if not isinstance(p2, Vector2f):
            log.error(f'parameter `p2` is not an object of type `{Vector2f}`')
        self._p2 = p2

    @property
    def thickness(self):
        return self._thickness

    @thickness.setter
    def thickness(self, thickness):
        if not isinstance(thickness, float):
            log.error(f'parameter `thickness` is not an object of type `{float}`')
        self._thickness = thickness

    @property
    def type(self):
        return self._type

    @type.setter
    def type(self, type):
        if not isinstance(type, SSL_FieldShapeType):
            log.error(f'parameter `type` is not an object of type `{SSL_FieldShapeType}`')
        self._type = type
    
    def __setattr__(self, name: object, value: object) -> None:
        '''overloaded __setattr__ for handling protobuf `Vector2f` message field type
        '''
        match name:
            case 'p1' | 'p2':
                point = Vector2f()
                point.x = value['x']
                point.y = value['y']
                value = point

        object.__setattr__(self, name, value)


class SSL_FieldCircularArc:
    def __init__(self, **kwargs) -> None:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_FieldCircularArc`
        """
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, name):
        if not isinstance(name, str):
            log.error(f'parameter `name` is not an object of type `{str}`')
        self._name = name

    @property
    def center(self):
        return self._center

    @center.setter
    def center(self, center):
        if not isinstance(center, Vector2f):
            log.error(f'parameter `center` is not an object of type `{Vector2f}`')
        self._center = center

    @property
    def radius(self):
        return self._radius

    @radius.setter
    def radius(self, radius):
        if not isinstance(radius, Vector2f):
            log.error(f'parameter `radius` is not an object of type `{Vector2f}`')
        self._radius = radius

    @property
    def a1(self):
        return self._a1

    @a1.setter
    def a1(self, a1):
        if not isinstance(a1, float):
            log.error(f'parameter `a1` is not an object of type `{float}`')
        self._a1 = a1

    @property
    def a2(self):
        return self._a2

    @a2.setter
    def a2(self, a2):
        if not isinstance(a2, float):
            log.error(f'parameter `a2` is not an object of type `{float}`')
        self._a2 = a2

    @property
    def thickness(self):
        return self._thickness

    @thickness.setter
    def thickness(self, thickness):
        if not isinstance(thickness, float):
            log.error(f'parameter `thickness` is not an object of type `{float}`')
        self._thickness = thickness

    @property
    def type(self):
        return self._type

    @type.setter
    def type(self, type):
        if not isinstance(type, SSL_FieldShapeType):
            log.error(f'parameter `type` is not an object of type `{SSL_FieldShapeType}`')
        self._type = type

    def __setattr__(self, name: object, value: object) -> None:
        '''overloaded __setattr__ for handling protobuf `Vector2f` and `SSL_FieldShapeType` message field type
        '''
        match name:
            case 'center' | 'radius':
                point = Vector2f()
                point.x = value['x']
                point.y = value['y']
                value = point
            
            case 'type':
                type = SSL_FieldShapeType[value]
                value = type

        object.__setattr__(self, name, value)


class SSL_GeometryFieldSize:
    def __init__(self, **kwargs) -> None:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_GeometryFieldSize`
        """
        
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def field_length(self):
        return self._field_length

    @field_length.setter
    def field_length(self, field_length):
        if not isinstance(field_length, int):
            log.error(f'parameter `field_length` is not an object of type `{int}`')
        self._field_length = field_length

    @property
    def goal_width(self):
        return self._goal_width

    @goal_width.setter
    def goal_width(self, goal_width):
        if not isinstance(goal_width, int):
            log.error(f'parameter `goal_width` is not an object of type `{int}`')
        self._goal_width = goal_width

    @property
    def goal_depth(self):
        return self._goal_depth

    @goal_depth.setter
    def goal_depth(self, goal_depth):
        if not isinstance(goal_depth, int):
            log.error(f'parameter `goal_depth` is not an object of type `{int}`')
        self._goal_depth = goal_depth

    @property
    def boundary_width(self):
        return self._boundary_width

    @boundary_width.setter
    def boundary_width(self, boundary_width):
        if not isinstance(boundary_width, int):
            log.error(f'parameter `boundary_width` is not an object of type `{int}`')
        self._boundary_width = boundary_width

    @property
    def field_lines(self):
        return self._field_lines

    @field_lines.setter
    def field_lines(self, field_lines):
        if not isinstance(field_lines, SSL_FieldLineSegment):
            log.error(f'parameter `field_lines` is not an object of type `{SSL_FieldLineSegment}`')
        self._field_lines = field_lines

    @property
    def field_arcs(self):
        return self._field_arcs

    @field_arcs.setter
    def field_arcs(self, field_arcs):
        if not isinstance(field_arcs, SSL_FieldCircularArc):
            log.error(f'parameter `field_arcs` is not an object of type `{SSL_FieldCircularArc}`')
        self._field_arcs = field_arcs

    @property
    def penalty_area_depth(self):
        return self._penalty_area_depth

    @penalty_area_depth.setter
    def penalty_area_depth(self, penalty_area_depth):
        if not isinstance(penalty_area_depth, int):
            log.error(f'parameter `penalty_area_depth` is not an object of type `{int}`')
        self._penalty_area_depth = penalty_area_depth

    @property
    def penalty_area_width(self):
        return self._penalty_area_width

    @penalty_area_width.setter
    def penalty_area_width(self, penalty_area_width):
        if not isinstance(penalty_area_width, int):
            log.error(f'parameter `penalty_area_width` is not an object of type `{int}`')
        self._penalty_area_width = penalty_area_width

    def __setattr__(self, name: object, value: object) -> None:
        '''overloaded __setattr__ for handling protobuf `SSL_FieldLineSegment` and `SSL_FieldCircularArc` message field type
        '''
        match name:
            case 'field_lines':
                field_line_segment = SSL_FieldLineSegment(**value)
                value = field_line_segment
            
            case 'field_arcs':
                field_circular_arc = SSL_FieldCircularArc(**value)
                value = field_circular_arc

        object.__setattr__(self, name, value)


class SSL_GeometryCameraCalibration:
    def __init__(self, **kwargs) -> None:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_GeometryCameraCalibration`
        """
        
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def camera_id(self):
        return self._camera_id

    @camera_id.setter
    def camera_id(self, camera_id):
        if not isinstance(camera_id, int):
            log.error(f'parameter `camera_id` is not an object of type `{int}`')
        self._camera_id = camera_id

    @property
    def focal_length(self):
        return self._focal_length

    @focal_length.setter
    def focal_length(self, focal_length):
        if not isinstance(focal_length, float):
            log.error(f'parameter `focal_length` is not an object of type `{float}`')
        self._focal_length = focal_length

    @property
    def principal_point_x(self):
        return self._principal_point_x

    @principal_point_x.setter
    def principal_point_x(self, principal_point_x):
        if not isinstance(principal_point_x, float):
            log.error(f'parameter `principal_point_x` is not an object of type `{float}`')
        self._principal_point_x = principal_point_x

    @property
    def principal_point_y(self):
        return self._principal_point_y

    @principal_point_y.setter
    def principal_point_y(self, principal_point_y):
        if not isinstance(principal_point_y, float):
            log.error(f'parameter `principal_point_y` is not an object of type `{float}`')
        self._principal_point_y = principal_point_y

    @property
    def distortion(self):
        return self._distortion

    @distortion.setter
    def distortion(self, distortion):
        if not isinstance(distortion, float):
            log.error(f'parameter `distortion` is not an object of type `{float}`')
        self._distortion = distortion

    @property
    def q0(self):
        return self._q0

    @q0.setter
    def q0(self, q0):
        if not isinstance(q0, float):
            log.error(f'parameter `q0` is not an object of type `{float}`')
        self._q0 = q0

    @property
    def q1(self):
        return self._q1

    @q1.setter
    def q1(self, q1):
        if not isinstance(q1, float):
            log.error(f'parameter `q1` is not an object of type `{float}`')
        self._q1 = q1

    @property
    def q2(self):
        return self._q2

    @q2.setter
    def q2(self, q2):
        if not isinstance(q2, float):
            log.error(f'parameter `q2` is not an object of type `{float}`')
        self._q2 = q2

    @property
    def q3(self):
        return self._q3

    @q3.setter
    def q3(self, q3):
        if not isinstance(q3, float):
            log.error(f'parameter `q3` is not an object of type `{float}`')
        self._q3 = q3

    @property
    def tx(self):
        return self._tx

    @tx.setter
    def tx(self, tx):
        if not isinstance(tx, float):
            log.error(f'parameter `tx` is not an object of type `{float}`')
        self._tx = tx

    @property
    def ty(self):
        return self._ty

    @ty.setter
    def ty(self, ty):
        if not isinstance(ty, float):
            log.error(f'parameter `ty` is not an object of type `{float}`')
        self._ty = ty

    @property
    def tz(self):
        return self._tz

    @tz.setter
    def tz(self, tz):
        if not isinstance(tz, float):
            log.error(f'parameter `tz` is not an object of type `{float}`')
        self._tz = tz

    @property
    def derived_camera_world_tx(self):
        return self._derived_camera_world_tx

    @derived_camera_world_tx.setter
    def derived_camera_world_tx(self, derived_camera_world_tx):
        if not isinstance(derived_camera_world_tx, float):
            log.error(f'parameter `derived_camera_world_tx` is not an object of type `{float}`')
        self._derived_camera_world_tx = derived_camera_world_tx

    @property
    def derived_camera_world_ty(self):
        return self._derived_camera_world_ty

    @derived_camera_world_ty.setter
    def derived_camera_world_ty(self, derived_camera_world_ty):
        if not isinstance(derived_camera_world_ty, float):
            log.error(f'parameter `derived_camera_world_ty` is not an object of type `{float}`')
        self._derived_camera_world_ty = derived_camera_world_ty

    @property
    def derived_camera_world_tz(self):
        return self._derived_camera_world_tz

    @derived_camera_world_tz.setter
    def derived_camera_world_tz(self, derived_camera_world_tz):
        if not isinstance(derived_camera_world_tz, float):
            log.error(f'parameter `derived_camera_world_tz` is not an object of type `{float}`')
        self._derived_camera_world_tz = derived_camera_world_tz

    @property
    def pixel_image_width(self):
        return self._pixel_image_width

    @pixel_image_width.setter
    def pixel_image_width(self, pixel_image_width):
        if not isinstance(pixel_image_width, int):
            log.error(f'parameter `pixel_image_width` is not an object of type `{int}`')
        self._pixel_image_width = pixel_image_width

    @property
    def pixel_image_height(self):
        return self._pixel_image_height

    @pixel_image_height.setter
    def pixel_image_height(self, pixel_image_height):
        if not isinstance(pixel_image_height, int):
            log.error(f'parameter `pixel_image_height` is not an object of type `{int}`')
        self._pixel_image_height = pixel_image_height

class SSL_BallModelStraightTwoPhase:
    def __init__(self, **kwargs) -> None:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_BallModelStraightTwoPhase`
        """
        
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])
            
    @property
    def acc_slide(self):
        return self._acc_slide

    @acc_slide.setter
    def acc_slide(self, acc_slide):
        if not isinstance(acc_slide, int):
            log.error(f'parameter `acc_slide` is not an object of type `{acc_slide}`')
        self._acc_slide = acc_slide

    @property
    def acc_roll(self):
        return self._acc_roll

    @acc_roll.setter
    def acc_roll(self, acc_roll):
        if not isinstance(acc_roll, int):
            log.error(f'parameter `acc_roll` is not an object of type `{int}`')
        self._acc_roll = acc_roll

    @property
    def k_switch(self):
        return self._k_switch

    @k_switch.setter
    def k_switch(self, k_switch):
        if not isinstance(k_switch, int):
            log.error(f'parameter `k_switch` is not an object of type `{int}`')
        self._k_switch = k_switch

class SSL_BallModelChipFixedLoss:
    def __init__(self, **kwargs) -> None:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_BallModelChipFixedLoss`
        """
        
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def damping_xy_first_hop(self):
        return self._damping_xy_first_hop

    @damping_xy_first_hop.setter
    def damping_xy_first_hop(self, damping_xy_first_hop):
        if not isinstance(damping_xy_first_hop, int):
            log.error(f'parameter `damping_xy_first_hop` is not an object of type `{int}`')
        self._damping_xy_first_hop = damping_xy_first_hop

    @property
    def damping_xy_other_hops(self):
        return self._damping_xy_other_hops

    @damping_xy_other_hops.setter
    def damping_xy_other_hops(self, damping_xy_other_hops):
        if not isinstance(damping_xy_other_hops, int):
            log.error(f'parameter `damping_xy_other_hops` is not an object of type `{int}`')
        self._damping_xy_other_hops = damping_xy_other_hops

    @property
    def damping_z(self):
        return self._damping_z

    @damping_z.setter
    def damping_z(self, damping_z):
        if not isinstance(damping_z, int):
            log.error(f'parameter `damping_z` is not an object of type `{int}`')
        self._damping_z = damping_z

class SSL_GeometryModels:
    def __init__(self, **kwargs) -> None:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_GeometryModels`
        """
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])

    @property
    def straight_two_phase(self):
        return self._straight_two_phase

    @straight_two_phase.setter
    def straight_two_phase(self, straight_two_phase):
        if not isinstance(straight_two_phase, SSL_BallModelStraightTwoPhase):
            log.error(f'parameter `straight_two_phase` is not an object of type `{SSL_BallModelStraightTwoPhase}`')
        self._straight_two_phase = straight_two_phase

    @property
    def chip_fixed_loss(self):
        return self._chip_fixed_loss

    @chip_fixed_loss.setter
    def chip_fixed_loss(self, chip_fixed_loss):
        if not isinstance(chip_fixed_loss, SSL_BallModelChipFixedLoss):
            log.error(f'parameter `chip_fixed_loss` is not an object of type `{SSL_BallModelChipFixedLoss}`')
        self._chip_fixed_loss = chip_fixed_loss

    def __setattr__(self, name: object, value: object) -> None:
        '''overloaded __setattr__ for handling protobuf `SSL_BallModelStraightTwoPhase` and `SSL_BallModelChipFixedLoss` message field type
        '''
        match name:
            case 'straight_two_phase':
                straight_two_phase = SSL_BallModelStraightTwoPhase(**value)
                value = straight_two_phase
            
            case 'chip_fixed_loss':
                chip_fixed_loss = SSL_BallModelChipFixedLoss(**value)
                value = chip_fixed_loss

        object.__setattr__(self, name, value)

class SSL_GeometryData:
    def __init__(self, **kwargs) -> None:
        """
        **kwargs : dict, optional
            refer to :doc:`src/TeamControl/SSL/proto2/ssl_vision_geometry.proto` for 
            the structure of `SSL_GeometryData`
        """
        
        for kw in kwargs:
            setattr(self, kw, kwargs[kw])
                
    @property
    def field(self):
        return self._field

    @field.setter
    def field(self, field):
        if not isinstance(field, SSL_GeometryFieldSize):
            log.error(f'parameter `field` is not an object of type `{SSL_GeometryFieldSize}`')
        self._field = field

    @property
    def calib(self):
        return self._calib

    @calib.setter
    def calib(self, calib):
        if not isinstance(calib, list):
            log.error(f'parameter `calib` is not an object of type `{list}`')
        self._calib = calib

    @property
    def models(self):
        return self._models

    @models.setter
    def models(self, models):
        if not isinstance(models, SSL_GeometryModels):
            log.error(f'parameter `models` is not an object of type `{SSL_GeometryModels}`')
        self._models = models