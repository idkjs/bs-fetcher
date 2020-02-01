// type body;
// type bodyInit;
// type headers;
// type headersInit;
// type response;
// type request;
// type requestInit;
// type arrayBuffer;
// type blob;
// type bufferSource;
// type formData;
// type readableStream;
// type urlSearchParams;

// module Method: {
//   type t = string;
//   let get: string;
//   let head: string;
//   let post: string;
//   let put: string;
//   let delete: string;
//   let connect: string;
//   let options: string;
//   let trace: string;
//   let patch: string;
//   let other: 'a => 'a;
// };
// module ReferrerPolicy: {
//   type t = string;
//   let none: string;
//   let noReferrer: string;
//   let noReferrerWhenDowngrade: string;
//   let sameOrigin: string;
//   let origin: string;
//   let strictOrigin: string;
//   let originWhenCrossOrigin: string;
//   let strictOriginWhenCrossOrigin: string;
//   let unsafeUrl: string;
// };
// module RequestType: {
//   type t = string;
//   let none: string;
//   let audio: string;
//   let font: string;
//   let image: string;
//   let script: string;
//   let style: string;
//   let track: string;
//   let video: string;
// };
// module RequestDestination: {
//   type t = string;
//   let none: string;
//   let document: string;
//   let embed: string;
//   let font: string;
//   let image: string;
//   let manifest: string;
//   let media: string;
//   let object_: string;
//   let report: string;
//   let script: string;
//   let serviceWorker: string;
//   let sharedWorker: string;
//   let style: string;
//   let worker: string;
//   let xslt: string;
// };
// module RequestMode: {
//   type t = string;
//   let navigate: string;
//   let sameOrigin: string;
//   let noCORS: string;
//   let cors: string;
// };
// module RequestCredentials: {
//   type t = string;
//   let omit: string;
//   let sameOrigin: string;
//   let include_: string;
// };
// module RequestCache: {
//   type t = string;
//   let default: string;
//   let noStore: string;
//   let reload: string;
//   let noCache: string;
//   let forceCache: string;
//   let onlyIfCached: string;
// };
// module RequestRedirect: {
//   type t = string;
//   let follow: string;
//   let error: string;
//   let manual: string;
// };
// module HeadersInit: {
//   type t = headersInit;
//   external make: Js.t({..}) => t = "%identity";
//   external makeWithArray: array((string, string)) => t = "%identity";
// };

// module Headers: {
//   type t = headers;
//   [@bs.new] external make: t = "Headers";
//   [@bs.new] external makeWithInit: headersInit => t = "Headers";
//   [@bs.send.pipe: t] external append: string => string = "append";
//   [@bs.send.pipe: t] external delete: string = "delete";
//   [@bs.send.pipe: t] [@bs.return {null_to_opt: null_to_opt}]
//   external get: string => option(string) = "get";
//   [@bs.send.pipe: t] external has: string => bool = "has";
//   [@bs.send.pipe: t] external set: (string, string) => unit = "set";
// };
// module BodyInit: {
//   type t = bodyInit;
//   external make: string => t = "%identity";
//   external makeWithBlob: blob => t = "%identity";
//   external makeWithBufferSource: bufferSource => t = "%identity";
//   external makeWithFormData: formData => t = "%identity";
//   external makeWithUrlSearchParams: urlSearchParams => t = "%identity";
// };
// module Body: {
//   type t = body;
//   [@bs.get] external body: t => readableStream = "body";
//   [@bs.get] external bodyUsed: t => bool = "bodyUsed";
//   [@bs.send.pipe: t]
//   external arrayBuffer: Js.Promise.t(arrayBuffer) = "arrayBuffer";
//   [@bs.send.pipe: t] external blob: Js.Promise.t(blob) = "blob";
//   [@bs.send.pipe: t] external formData: Js.Promise.t(formData) = "formData";
//   [@bs.send.pipe: t] external json: Js.Promise.t(Js.Json.t) = "json";
//   [@bs.send.pipe: t] external text: Js.Promise.t(string) = "text";
// };

// module RequestInit: {
//   type t = requestInit;
//   let make:
//     (
//       ~_method: Method.t=?,
//       ~headers: headersInit=?,
//       ~body: bodyInit=?,
//       ~referrer: string=?,
//       ~referrerPolicy: ReferrerPolicy.t=?,
//       ~mode: RequestMode.t=?,
//       ~credentials: RequestCredentials.t=?,
//       ~cache: RequestCache.t=?,
//       ~redirect: RequestRedirect.t=?,
//       ~integrity: string=?,
//       ~keepalive: bool=?,
//       unit
//     ) =>
//     t;
// };


// module Request: {
//   type t = request;
//   [@bs.new] external make: string => t = "Request";
//   [@bs.new] external makeWithInit: (string, requestInit) => t = "Request";
//   [@bs.new] external makeWithRequest: t => t = "Request";
//   [@bs.new] external makeWithRequestInit: (t, requestInit) => t = "Request";
//   let method: t => Method.t;
//   [@bs.get] external url: t => string = "url";
//   [@bs.get] external headers: t => headers = "headers";
//   let type_: t => RequestType.t;
//   let destination: t => RequestDestination.t;
//   [@bs.get] external referrer: t => string = "referrer";
//   let referrerPolicy: t => ReferrerPolicy.t;
//   let mode: t => RequestMode.t;
//   let credentials: t => RequestCredentials.t;
//   let cache: t => RequestCache.t;
//   let redirect: t => RequestRedirect.t;
//   [@bs.get] external integrity: t => string = "integrity";
//   [@bs.get] external keepalive: t => bool = "keepalive";
//   /* Body Impl */
//   [@bs.get] external body: t => readableStream = "body";
//   [@bs.get] external bodyUsed: t => bool = "bodyUsed";
//   [@bs.send.pipe: t] external arrayBuffer: Js.Promise.t(arrayBuffer) = "arrayBuffer";
//   [@bs.send.pipe: t] external blob: Js.Promise.t(blob) = "blob";
//   [@bs.send.pipe: t] external formData: Js.Promise.t(formData) = "formData";
//   [@bs.send.pipe: t] external json: Js.Promise.t(Js.Json.t) = "json";
//   [@bs.send.pipe: t] external text: Js.Promise.t(string) = "text";
// };

// module Response: {
//   type t = response;
//   [@bs.val] external error: unit => t = "error";
//   [@bs.val] external redirect: string => t = "redirect";
//   [@bs.val]
//   external redirectWithStatus: (string, int /* enum-ish */) => t = "redirect";
//   [@bs.get] external headers: t => headers = "headers";
//   [@bs.get] external ok: t => bool = "ok";
//   [@bs.get] external redirected: t => bool = "redirected";
//   [@bs.get] external status: t => int = "status";
//   [@bs.get] external statusText: t => string = "statusText";
//   [@bs.get] external _type: t => string = "type";
//   [@bs.get] external url: t => string = "url";
//   [@bs.send.pipe: t] external clone: t = "clone";
// };

// // bindings to fetch in browser
// [@bs.val] external fetch: string => Js.Promise.t(response) = "fetch";
// [@bs.val]
// external fetchWithInit: (string, requestInit) => Js.Promise.t(response) =
//   "fetch";
// [@bs.val]
// external fetchWithRequest: request => Js.Promise.t(response) = "fetch";
// [@bs.val]
// external fetchWithRequestInit:
//   (request, requestInit) => Js.Promise.t(response) =
//   "fetch";