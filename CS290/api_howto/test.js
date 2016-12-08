var baseURL = "https://openapi.etsy.com/v2/shops/";
var apiKey = "yytys7tcm73htzzb4f7npm70";
var shopName = "emandsprout";

function displayListings() {
  $.ajax({
    url: baseURL + shopName + "/listings/active.js?api_key=" + apiKey +
    "&includes=MainImage&fields=url,price,title,description&limit=10",
    dataType: "jsonp",

    success: function (resp) {
      for (i = 0; i < resp.results.length; i++) {
        $('#shop').append('<div style="display: inline-block"><a href="' + resp.results[i].url +
        '" target="_blank">' + '<img alt="' + resp.results[i].description + '" src="' +
        resp.results[i].MainImage.url_170x135 +
        '" title="' + resp.results[i].title + '"></img></a><center>$' +
        resp.results[i].price + '</div>');
      }
    }
  });
}

$(document).ready(function () {
  displayListings();
});
