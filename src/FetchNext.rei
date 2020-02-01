type body;

type bodyInit;

type headers;

type headersInit;

type response;

type request;

type requestInit;

/* external */
type arrayBuffer; /* TypedArray */

type blob; /* FileAPI */

type bufferSource; /* Web IDL, either an arrayBuffer or arrayBufferView */

type formData; /* XMLHttpRequest */

type readableStream; /* Streams */

type urlSearchParams; /* URL */

module Method: {
  type t = string;
  let get: t;
  let head: t;
  let post: t;
  let put: t;
  let delete: t;
  let connect: t;
  let options: t;
  let trace: t;
  let patch: t;
  let other: string => t;
};

module ReferrerPolicy: {
  type t = string;
  let none: t;
  let noReferrer: t;
  let noReferrerWhenDowngrade: t;
  let sameOrigin: t;
  let origin: t;
  let strictOrigin: t;
  let originWhenCrossOrigin: t;
  let strictOriginWhenCrossOrigin: t;
  let unsafeUrl: t;
};

module RequestType: {
  type t = string;
  let none: t;
  let audio: t;
  let font: t;
  let image: t;
  let script: t;
  let style: t;
  let track: t;
  let video: t;
};

module RequestDestination: {
  type t = string;
  let none: t;
  let document: t;
  let embed: t;
  let font: t;
  let image: t;
  let manifest: t;
  let media: t;
  let object_: t;
  let report: t;
  let script: t;
  let serviceWorker: t;
  let sharedWorker: t;
  let style: t;
  let worker: t;
  let xslt: t;
};

module RequestMode: {
  type t = string;
  let navigate: t;
  let sameOrigin: t;
  let noCORS: t;
  let cors: t;
};

module RequestCredentials: {
  type t = string;
  let omit: t;
  let sameOrigin: t;
  let include_: t;
};

module RequestCache: {
  type t = string;
  let default: t;
  let noStore: t;
  let reload: t;
  let noCache: t;
  let forceCache: t;
  let onlyIfCached: t;
};

module RequestRedirect: {
  type t = string;
  let follow: t;
  let error: t;
  let manual: t;
};

module HeadersInit: {
  type t = headersInit;
  external make: Js.t({..}) => t = "%identity";
  external makeWithArray: array((string, string)) => t = "%identity";
};

module Headers: {
  type t = headers;
  [@bs.new] external make: t = "Headers";
  [@bs.new] external makeWithInit: headersInit => t = "Headers";
  [@bs.send.pipe: t] external append: string => string = "append";
  [@bs.send.pipe: t] external delete: string = "delete" /* very experimental */; /* entries */
  [@bs.send.pipe: t] [@bs.return {null_to_opt: null_to_opt}]
  external get: string => option(string) = "get";
  [@bs.send.pipe: t] external has: string => bool = "has" /* very experimental */; /* keys */
  [@bs.send.pipe: t] external set: (string, string) => unit = "set" /* very experimental */; /* values */
};

module BodyInit: {
  type t = bodyInit;
  external make: string => t = "%identity";
  external makeWithBlob: blob => t = "%identity";
  external makeWithBufferSource: bufferSource => t = "%identity";
  external makeWithFormData: formData => t = "%identity";
  external makeWithUrlSearchParams: urlSearchParams => t = "%identity";
};

module Body: {
  type t = body;
  [@bs.get] external body: t => readableStream = "body";
  [@bs.get] external bodyUsed: t => bool = "bodyUsed";
  [@bs.send.pipe: t]
  external arrayBuffer: Js.Promise.t(arrayBuffer) = "arrayBuffer";
  [@bs.send.pipe: t] external blob: Js.Promise.t(blob) = "blob";
  [@bs.send.pipe: t] external formData: Js.Promise.t(formData) = "formData";
  [@bs.send.pipe: t] external json: Js.Promise.t(Js.Json.t) = "json";
  [@bs.send.pipe: t] external text: Js.Promise.t(string) = "text";
};

module RequestInit: {
  type t = requestInit;
  let make:
    (
      ~_method: Method.t=?,
      ~headers: headersInit=?,
      ~body: bodyInit=?,
      ~referrer: string=?,
      ~referrerPolicy: ReferrerPolicy.t=?,
      ~mode: RequestMode.t=?,
      ~credentials: RequestCredentials.t=?,
      ~cache: RequestCache.t=?,
      ~redirect: RequestRedirect.t=?,
      ~integrity: string=?,
      ~keepalive: bool=?,
      unit
    ) =>
    t;
};

module Request: {
  type t = request;
  [@bs.new] external make: string => t = "Request";
  [@bs.new] external makeWithInit: (string, requestInit) => t = "Request";
  [@bs.new] external makeWithRequest: t => t = "Request";
  [@bs.new] external makeWithRequestInit: (t, requestInit) => t = "Request";
  let _method: t => Method.t;
  [@bs.get] external url: t => string = "url";
  [@bs.get] external headers: t => headers = "headers";
  let type_: t => RequestType.t;
  let destination: t => RequestDestination.t;
  [@bs.get] external referrer: t => string = "referrer";
  let referrerPolicy: t => ReferrerPolicy.t;
  let mode: t => RequestMode.t;
  let credentials: t => RequestCredentials.t;
  let cache: t => RequestCache.t;
  let redirect: t => RequestRedirect.t;
  [@bs.get] external integrity: t => string = "integrity";
  [@bs.get] external keepalive: t => bool = "keepalive";
  /* Body Impl */
  [@bs.get] external body: t => readableStream = "body";
  [@bs.get] external bodyUsed: t => bool = "bodyUsed";
  [@bs.send.pipe: t]
  external arrayBuffer: Js.Promise.t(arrayBuffer) = "arrayBuffer";
  [@bs.send.pipe: t] external blob: Js.Promise.t(blob) = "blob";
  [@bs.send.pipe: t] external formData: Js.Promise.t(formData) = "formData";
  [@bs.send.pipe: t] external json: Js.Promise.t(Js.Json.t) = "json";
  [@bs.send.pipe: t] external text: Js.Promise.t(string) = "text";
};

module Response: {
  type t = response;
  [@bs.val] external error: unit => t = "error";
  [@bs.val] external redirect: string => t = "redirect";
  [@bs.val] external redirectWithStatus: (string, int) => t = "redirect";
  [@bs.get] external headers: t => headers = "header";
  [@bs.get] external ok: t => bool = "bool";
  [@bs.get] external redirected: t => bool = "redirected";
  [@bs.get] external status: t => int = "status";
  [@bs.get] external statusText: t => string = "string";
  [@bs.get] external _type: t => string = "string";
  [@bs.get] external url: t => string = "string";
  [@bs.send.pipe: t] external clone: t = "clone";
  /* Body.Impl */
  [@bs.get] external body: t => readableStream = "body";
  [@bs.get] external bodyUsed: t => bool = "bodyUsed";
  [@bs.send.pipe: t]
  external arrayBuffer: Js.Promise.t(arrayBuffer) = "arrayBuffer";
  [@bs.send.pipe: t] external blob: Js.Promise.t(blob) = "blob";
  [@bs.send.pipe: t] external formData: Js.Promise.t(formData) = "formData";
  [@bs.send.pipe: t] external json: Js.Promise.t(Js.Json.t) = "json";
  [@bs.send.pipe: t] external text: Js.Promise.t(string) = "text";
};

[@bs.val] external fetch: string => Js.Promise.t(response) = "fetch";

[@bs.val]
external fetchWithInit: (string, requestInit) => Js.Promise.t(response) =
  "fetch";

[@bs.val]
external fetchWithRequest: request => Js.Promise.t(response) = "fetch";

[@bs.val]
external fetchWithRequestInit:
  (request, requestInit) => Js.Promise.t(response) =
  "fetch";