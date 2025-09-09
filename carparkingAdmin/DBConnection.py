import firebase.firebase
import random
import firebase_admin
import firebase_auth.firebase_auth
import requests.exceptions
from firebase_admin import credentials
from firebase_admin import db

"""
update = ref.update({})
set = ref.set({})
"""

api_key="AIzaSyBgd59afUVZ-1YRpucWC7LCqieOjQr5Lko"
cred = credentials.Certificate('firebase_sdk.json')
auth = firebase_auth.firebase_auth.Auth(api_key,98,cred)
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://car-parking-dee89-default-rtdb.firebaseio.com/'
})

ref_locations = '/Car Parking/Locations'


def login(username:str,password:str):
    try:
        json1 = auth.sign_in_with_email_and_password(username,password)
        if json1 is not None:
            return 1
        else:
            return 0
    except Exception as e:
        return 0

def addLocation(location:str,address:str):
    db.reference(ref_locations).push({
            'location':location,
            'address':address
    })

def getLocations():
    locations = db.reference(ref_locations).get()

    return locations

