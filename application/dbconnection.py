import firebase_admin
from firebase_admin import credentials, firestore, auth

# Initialize Firebase
cred = credentials.Certificate("firebase_sdk.json")
firebase_admin.initialize_app(cred)

# Firestore database client
db = firestore.client()
# Initialize Firebase
cred = credentials.Certificate('firebase_sdk.json')
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://car-parking-dee89-default-rtdb.firebaseio.com/'
})

ref_locations = '/Car Parking/Locations'

# Hardcoded login
def login(username: str, password: str):
    if username == "admin" and password == "admin123":
        return 1
    return 0

# Add new location
def addLocation(location: str, address: str):
    db.reference(ref_locations).push({
        'location': location,
        'address': address
    })

# Fetch all locations
def getLocations():
    return db.reference(ref_locations).get()
