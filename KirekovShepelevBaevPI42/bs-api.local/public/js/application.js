(function($, APP) {
    'use strict';

    /**
     * Контроллер приложения, запускает контроллеры страниц
     **/
    APP.Controls.Application = can.Control.extend({

        /**
         *
         **/
        init: function() {
            this.initPageController();
        },

        /**
         *
         **/
        initPageController: function() {
            var pagePlugin = can.capitalize(can.camelize(this.element.data('page-type')));
            if (APP.Controls.Page[pagePlugin]) {
                new APP.Controls.Page[pagePlugin](this.element);
            }
        }
    });

    /**
     * Bootstrap
     */
    $(function() {
        new APP.Controls.Application($('body'));
    });

})(jQuery, window.APP);