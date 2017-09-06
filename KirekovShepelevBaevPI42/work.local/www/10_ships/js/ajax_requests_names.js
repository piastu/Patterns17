
function getCurrentDomain() {
    return 'http://bs-api.local/public'
}

var API_METHODS = {

    apiStart: function () {
        return getCurrentDomain() + '/api/start/';
    },

    apiPlaceShip: function (id, code) {
        return getCurrentDomain() + '/api/place-ship/' + id + '/' + code;
    },

    apiClearField: function (id, code) {
        return getCurrentDomain() + '/api/clear-field/' + id + '/' + code;
    },

    apiGetStatus: function (id, code) {
        return getCurrentDomain() + '/api/status/' + id + '/' + code;
    },
    
    apiPlayerReady: function (id, code) {
        return getCurrentDomain() + '/api/ready/' + id + '/' + code;
    },

    apiShot: function (id, code) {
        return getCurrentDomain() + '/api/shot/' + id + '/' + code;
    }

};