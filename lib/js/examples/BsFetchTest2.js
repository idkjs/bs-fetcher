'use strict';

var Js_json = require("bs-platform/lib/js/js_json.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");

((require('isomorphic-fetch')));

var dogsUrl = "https://dog.ceo/api/breeds/image/random/5";

console.log("https://dog.ceo/api/breeds/image/random/5");

console.log("_________________");

function $$throw (message){ throw new Error(message); };

fetch(dogsUrl).then((function (prim) {
                return prim.json();
              })).then((function (json) {
              return Promise.resolve(Js_json.decodeArray(json));
            })).then((function (opt) {
            return Promise.resolve(Belt_Option.getExn(opt));
          })).then((function (items) {
          return Promise.resolve(items.map((function (item) {
                            return Belt_Option.getExn(Js_json.decodeString(item));
                          })));
        })).catch((function (error) {
        return Promise.resolve($$throw(String(error)));
      }));

exports.dogsUrl = dogsUrl;
exports.$$throw = $$throw;
/*  Not a pure module */
