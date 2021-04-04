import time
import serial
import smtplib
TO = 'testfor362@gmail.com'
GMAIL_USER = 'testsendemail362'
GMAIL_PASS = 'Password here'
SUBJECT = 'Alert'
TEXT = 'Your sensor detected movement, someone access your are; and the divice has taken a pictuer!!!'


ser = serial.Serial('/dev/tty.usbmodem14101', 9600)


def send_email():
    print("Sending Email")
    smtpserver = smtplib.SMTP("smtp.gmail.com",587)
    smtpserver.ehlo()
    smtpserver.starttls()
    smtpserver.ehlo
    smtpserver.login(GMAIL_USER, GMAIL_PASS)
    header = 'To:' + TO + '\n' + 'From: ' + GMAIL_USER
    header = header + '\n' + 'Subject:' + SUBJECT + '\n'
    print (header)
    msg = header + '\n' + TEXT + ' \n\n'
    smtpserver.sendmail(GMAIL_USER, TO, msg)
    smtpserver.close()
    
while True:
    message = ser.readline()
    print(message)
    if message[0] == 'M' :
        send_email()
    time.sleep(0.5)

