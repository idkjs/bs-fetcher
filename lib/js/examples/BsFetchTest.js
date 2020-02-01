'use strict';

var Fetch = require("../src/Fetch.js");
var Js_json = require("bs-platform/lib/js/js_json.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

((require('isomorphic-fetch')));

var dogsUrl = "https://dog.ceo/api/breeds/image/random/5";

var jph = "https://jsonplaceholder.typicode.com/posts/";

fetch(dogsUrl).then((function (prim) {
          return prim.text();
        })).then((function (text) {
        return Promise.resolve((console.log(text), /* () */0));
      }));

console.log("http://httpbin.org/post");

console.log("_________________");

fetch("http://httpbin.org/post", Fetch.RequestInit.make(/* Post */2, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0)).then((function (prim) {
          return prim.text();
        })).then((function (text) {
        return Promise.resolve((console.log(text), /* () */0));
      }));

var payload = { };

payload["name"] = "Said";

payload["id"] = 23;

fetch(jph, Fetch.RequestInit.make(/* Post */2, undefined, Caml_option.some(JSON.stringify(payload)), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0)).then((function (prim) {
          return prim.text();
        })).then((function (text) {
        return Promise.resolve((console.log(text), /* () */0));
      }));

console.log("https://dog.ceo/api/breeds/image/random/5");

console.log("_________________");

fetch(dogsUrl).then((function (prim) {
              return prim.json();
            })).then((function (json) {
            return Promise.resolve(Js_json.decodeArray(json));
          })).then((function (opt) {
          return Promise.resolve(Belt_Option.getExn(opt));
        })).then((function (dogs) {
        return Promise.resolve(dogs.map((function (dog) {
                          return Belt_Option.getExn(Js_json.decodeString(dog));
                        })));
      }));

exports.dogsUrl = dogsUrl;
exports.jph = jph;
exports.payload = payload;
/*  Not a pure module */
