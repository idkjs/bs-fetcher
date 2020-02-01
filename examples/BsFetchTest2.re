open Fetcher;
[%raw "require('isomorphic-fetch')"];

let dogsUrl = "https://dog.ceo/api/breeds/image/random/5";
Js.log("https://dog.ceo/api/breeds/image/random/5");
Js.log("_________________");
let throw: string => 'a = [%raw message => {| throw new Error(message); |}];
let _ =
  Js.Promise.(
    Fetch.fetch(dogsUrl)
    /* assume server returns `["apple", "banana", "pear", ...]` */
    |> then_(Fetch.Response.json)
    |> then_(json => Js.Json.decodeArray(json) |> resolve)
    |> then_(opt => Belt.Option.getExn(opt) |> resolve)
    |> then_(items =>
         items
         |> Js.Array.map(item =>
              item |> Js.Json.decodeString |> Belt.Option.getExn
            )
         |> resolve
       )
    |> catch(error => throw(Js.String.make(error)) |> resolve)
  );