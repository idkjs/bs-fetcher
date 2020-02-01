open Fetcher;
[%raw "require('isomorphic-fetch')"];

let dogsUrl = "https://dog.ceo/api/breeds/image/random/5";
let jph = "https://jsonplaceholder.typicode.com/posts/";
let _ =
  Js.Promise.(
    FetchNext.fetch(dogsUrl)
    |> then_(FetchNext.Response.text)
    |> then_(text => print_endline(text) |> resolve)
  );

Js.log("http://httpbin.org/post");
Js.log("_________________");
let _ =
  Js.Promise.(
    FetchNext.fetchWithInit(
      "http://httpbin.org/post",
      FetchNext.RequestInit.make(~_method="Post", ()),
    )
    |> then_(FetchNext.Response.text)
    |> then_(text => print_endline(text) |> resolve)
  );
let payload = Js.Dict.empty();
Js.Dict.set(payload, "name", Js.Json.string("Said"));
Js.Dict.set(payload, "id", Js.Json.number(23.));

let _ =
  Js.Promise.(
    FetchNext.fetchWithInit(
      jph,
      FetchNext.RequestInit.make(
        ~_method="Post",
        ~body=
          FetchNext.BodyInit.make(Js.Json.stringify(Js.Json.object_(payload))),
        (),
      ),
    )
    |> then_(FetchNext.Response.text)
    |> then_(text => print_endline(text) |> resolve)
  );
Js.log("https://dog.ceo/api/breeds/image/random/5");
Js.log("_________________");
let _ =
  Js.Promise.(
    FetchNext.fetch(dogsUrl)
    /* assume server returns `["apple", "banana", "pear", ...]` */
    |> then_(FetchNext.Response.json)
    |> then_(json => Js.Json.decodeArray(json) |> resolve)
    |> then_(opt => Belt.Option.getExn(opt) |> resolve)
    |> then_(dogs =>
         dogs
         |> Js.Array.map(dog =>
              dog |> Js.Json.decodeString |> Belt.Option.getExn
            )
         |> resolve
       )
  );