$(function(){
    var winHeight = $(window).height();
    var headerHeight = $(".header").height();
    var spanHeight = winHeight - headerHeight -15;
    $("div.span10").height(spanHeight);

    var _input = $("div.upSub .nav li input");
    var _path = $("#path");
    _input.change(function(){
        _path.val(_input.val());
    });
});