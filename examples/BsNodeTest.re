open Fetcher;
open BsNodeFetch;
let _ =
  fetch("https://swapi.co/api/people/1");

let dogsUrl = "https://dog.ceo/api/breeds/image/random/5";
let _ =
  fetchWithInit(dogsUrl, RequestInit.make(~_method=Get, ()))
  |> Js.Promise.then_(Response.text)
  |> Js.Promise.then_(text => print_endline(text) |> Js.Promise.resolve);
