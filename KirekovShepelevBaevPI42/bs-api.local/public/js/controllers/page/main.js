(function($, APP) {
    'use strict';
    
    /**
     * Контроллер главной страницы
     **/
    APP.Controls.Page.Main = can.Control.extend({
    
        /**
         *
         **/
        init: function() {
            console.log('Using domain: ', localStorage.domain ? localStorage.domain : window.location.origin);
        },

        '.js-start-game click': function() {
            $.ajax({
                url: APP.Helpers.url('api-start', {}),
                method: 'post',
                dataType: 'json',
                success: function(data) {
                    if (data.success) {
                        window.location.href = APP.Helpers.url('placement', data, false);
                    } else {
                        alert(data.message);
                    }
                }
            });
        }
    
    });

})(jQuery, window.APP);