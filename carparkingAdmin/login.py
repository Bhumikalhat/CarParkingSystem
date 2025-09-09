import firebase_admin
from firebase_admin import *
import firebase.firebase as f


cred_obj = firebase_admin.credentials.Certificate('./firebaseConfig.json')
default_app = firebase_admin.initialize_app(cred_obj, {
    'databaseURL': "https://car-parking-dee89-default-rtdb.firebaseio.com/"
})

ref_data = db.reference('/Car Parking/data')
ref_locations = db.reference('Car Parking/Locations')


def addLocation(key: str, location: str, address: str):
    ref_locations.push({
        key: {
            'location': location,
            'address': address
        }
    })


key = ref_locations.push().key
addLocation(str(key), 'Sample1', '12345 Sample')
