(function($, APP) {
    'use strict';

    /**
     * Окно чата
     **/
    APP.Controls.Partial.Chat = can.Control.extend({

        lastTime: false,
        loadMessagesTimeout: false,
        prevScrollHeight: false,
        disabled: false,

        init: function() {
            this.$messages = this.element.find('.messages');
            this.$input = this.element.find('.js-input');

            var $el = this.$messages;
            $el.addClass('scroll-content');
            $el.wrap('<div class="scroll-wrap" />');
            var $wrap = $el.parent();
            $wrap.append( '<div class="baron_bar_v"><div class="main__bar"></div></div>' );
            $el.baron({bar: $wrap.find('.main__bar')});

            this._loadMessages();
            this.loadMessages();
        },

        '.js-submit click': function() {
            this.sendMessage();
        },

        'input keyup': function($el, ev) {
            if (ev.which == 13) {
                // ENTER
                this.sendMessage();
            }
        },

        /**
         *
         */
        sendMessage: function() {
            var message = this.$input.val();

            if ($.trim(message) == '') {
                this.$input.focus();
                return;
            }

            $.ajax({
                url: APP.Helpers.url('api-chat-send', APP.Helpers.getGameParams()),
                method: 'post',
                dataType: 'json',
                data: {
                    message: this.$input.val()
                },
                success: function(data) {
                    if (data.success) {
                        this.$input.val('');
                        this._loadMessages();
                        this.loadMessages();
                    } else {
                        alert(data.message);
                    }
                }.bind(this)
            });
        },

        loadMessages: function() {
            clearTimeout(this.loadMessagesTimeout);
            this.loadMessagesTimeout = setInterval(function() {
                this._loadMessages();
            }.bind(this), 5000);
        },

        _loadMessages: function() {
            if (this.disabled) return;

            $.ajax({
                url: APP.Helpers.url('api-chat-load', APP.Helpers.getGameParams()),
                method: 'get',
                dataType: 'json',
                data: {
                    lastTime: this.lastTime
                },
                success: function(data) {
                    if (data.success) {
                        this.appendMessages(data.messages);
                        this.lastTime = data.lastTime;
                    } else {
                        alert(data.message);
                        this.disabled = true;
                    }
                }.bind(this),
                error: function() {
                    this.disabled = true;
                }.bind(this)
            });
        },

        appendMessages: function(messages) {
            for (var i in messages) {
                if (!messages.hasOwnProperty(i)) continue;

                var $msg = $('<div class="msg"></div>');
                var text = '<span class="author">' + (messages[i].my ? 'Вы: ' : 'Противник: ') + '</span> ' + messages[i].message;
                $msg.append(text);
                this.$messages.append($msg);
            }

            var msg = this.$messages.get(0);
            if (this.prevScrollHeight != msg.scrollHeight) {
                msg.scrollTop = msg.scrollHeight;
                this.prevScrollHeight = msg.scrollHeight;
            }
        }
    });

})(jQuery, window.APP);