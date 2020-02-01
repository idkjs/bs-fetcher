'use strict';

var NodeFetch = require("node-fetch");
var BsNodeFetch = require("./BsNodeFetch.js");

NodeFetch.default("https://swapi.co/api/people/1");

var dogsUrl = "https://dog.ceo/api/breeds/image/random/5";

NodeFetch.default(dogsUrl, BsNodeFetch.RequestInit.make(/* Get */0, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0)).then((function (prim) {
          return prim.text();
        })).then((function (text) {
        return Promise.resolve((console.log(text), /* () */0));
      }));

exports.dogsUrl = dogsUrl;
/*  Not a pure module */
