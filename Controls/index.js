const firebaseConfig = {
    apiKey: "AIzaSyCmBcoW91xsKnvXjAUBZH3TzKEXkXShaMA",
    authDomain: "irremoteiot.firebaseapp.com",
    databaseURL: "https://irremoteiot-default-rtdb.europe-west1.firebasedatabase.app",
    projectId: "irremoteiot",
    storageBucket: "irremoteiot.appspot.com",
    messagingSenderId: "362888902535",
    appId: "1:362888902535:web:ff126c234591336c354522"
};
// Initialize Firebase
firebase.initializeApp(firebaseConfig);
firebase.analytics();

function SendHexCode(novihexcode) {
    firebase.database().ref("/").set({
        hexCode: novihexcode
    },
        (error) => {
            if (error) {
                console.log("Greška u snimanju podataka!");
            }
            else {
                console.log("Uspjeh");
            }
        });
}