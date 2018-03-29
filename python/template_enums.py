from enum import IntEnum, Enum


class AudioMode(object):
    """
    Values for _mode_ parameter of zroya.Template.audio method.
    Usage: template.audio(mode=zroya.AudioMode.Silence)
    """

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
    """
    This enumeration contains all accepted values for parameter _audio_ of zroya.Template.audio method.
    Usage: template.audio(audio=zroya.Audio.IM)
    """

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
    """
    All possible values for zroya.Template constructor.
    Usage: zroya.Template(zroya.TemplateType.ImageAndText2)
    """

    ImageAndText1 = 0
    """
    A large image and a single string wrapped across three lines of text.
    """

    ImageAndText2 = 1
    """
    A large image, one string of bold text on the first line, one string of regular text wrapped across the second and third lines.
    """

    ImageAndText3 = 2
    """
    A large image, one string of bold text wrapped across the first two lines, one string of regular text on the third line.
    """

    ImageAndText4 = 3
    """
    A large image, one string of bold text on the first line, one string of regular text on the second line, one string of regular text on the third line.
    """

    Text1 = 4
    """
    Single string wrapped across three lines of text.
    """

    Text2 = 5
    """
    One string of bold text on the first line, one string of regular text wrapped across the second and third lines.
    """

    Text3 = 6
    """
    One string of bold text wrapped across the first two lines, one string of regular text on the third line.
    """

    Text4 = 7
    """
    One string of bold text on the first line, one string of regular text on the second line, one string of regular text on the third line.
    """
