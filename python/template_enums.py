from enum import IntEnum, Enum


class AudioMode(IntEnum):
    Default = 0
    """
    Use default audio mode. Selected audio will be played only once.
    """
    Silence = 1
    """
    No audio is played at all.
    """
    Loop = 2
    """
    Play audio in loop until it is moved to Action Center. This time may vary due to different user configuration.
    """


class Audio(Enum):
    Default = "ms-winsoundevent:Notification.Default"
    IM = "ms-winsoundevent:Notification.IM"
    Mail = "ms-winsoundevent:Notification.Mail"
    Reminder = "ms-winsoundevent:Notification.Reminder"
    SMS = "ms-winsoundevent:Notification.SMS"
    Alarm = "ms-winsoundevent:Notification.Looping.Alarm"
    Alarm2 = "ms-winsoundevent:Notification.Looping.Alarm2"
    Alarm3 = "ms-winsoundevent:Notification.Looping.Alarm3"
    Alarm4 = "ms-winsoundevent:Notification.Looping.Alarm4"
    Alarm5 = "ms-winsoundevent:Notification.Looping.Alarm5"
    Alarm6 = "ms-winsoundevent:Notification.Looping.Alarm6"
    Alarm7 = "ms-winsoundevent:Notification.Looping.Alarm7"
    Alarm8 = "ms-winsoundevent:Notification.Looping.Alarm8"
    Alarm9 = "ms-winsoundevent:Notification.Looping.Alarm9"
    Alarm10 = "ms-winsoundevent:Notification.Looping.Alarm10"
    Call = "ms-winsoundevent:Notification.Looping.Call"
    Call2 = "ms-winsoundevent:Notification.Looping.Call2"
    Call3 = "ms-winsoundevent:Notification.Looping.Call3"
    Call4 = "ms-winsoundevent:Notification.Looping.Call4"
    Call5 = "ms-winsoundevent:Notification.Looping.Call5"
    Call6 = "ms-winsoundevent:Notification.Looping.Call6"
    Call7 = "ms-winsoundevent:Notification.Looping.Call7"
    Call8 = "ms-winsoundevent:Notification.Looping.Call8"
    Call9 = "ms-winsoundevent:Notification.Looping.Call9"
    Call10 = "ms-winsoundevent:Notification.Looping.Call10"


class TemplateType(IntEnum):
    ImageAndText1 = 0
    """

    """
    ImageAndText2 = 1
    ImageAndText3 = 3
    ImageAndText4 = 4
    Text1 = 5
    Text2 = 6
    Text3 = 7
    Text4 = 8
