'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");

function other(m) {
  return m;
}

var Method = {
  get: "GET",
  head: "HEAD",
  post: "POST",
  put: "PUT",
  $$delete: "DELETE",
  connect: "CONNECT",
  options: "OPTIONS",
  trace: "TRACE",
  patch: "PATCH",
  other: other
};

var ReferrerPolicy = {
  none: "",
  noReferrer: "no-referrer",
  noReferrerWhenDowngrade: "no-referrer-when-downgrade",
  sameOrigin: "same-origin",
  origin: "origin",
  strictOrigin: "strict-origin",
  originWhenCrossOrigin: "origin-when-cross-origin",
  strictOriginWhenCrossOrigin: "strict-origin-when-cross-origin",
  unsafeUrl: "unsafe-url"
};

var RequestType = {
  none: "",
  audio: "audio",
  font: "font",
  image: "image",
  script: "script",
  style: "style",
  track: "track",
  video: "video"
};

var RequestDestination = {
  none: "",
  $$document: "document",
  embed: "embed",
  font: "font",
  image: "image",
  manifest: "manifest",
  media: "media",
  object_: "object",
  report: "report",
  script: "script",
  serviceWorker: "serviceworker",
  sharedWorker: "sharedworder",
  style: "style",
  worker: "worker",
  xslt: "xslt"
};

var RequestMode = {
  navigate: "navigate",
  sameOrigin: "same-origin",
  noCORS: "no-cors",
  cors: "cors"
};

var RequestCredentials = {
  omit: "omit",
  sameOrigin: "same-origin",
  include_: "include"
};

var RequestCache = {
  $$default: "default",
  noStore: "no-store",
  reload: "reload",
  noCache: "no-cache",
  forceCache: "force-cache",
  onlyIfCached: "only-if-cached"
};

var RequestRedirect = {
  follow: "follow",
  error: "error",
  manual: "manual"
};

var HeadersInit = { };

var $$Headers = { };

var BodyInit = { };

var $$Response = { };

var Body = { };

var RequestInit = {
  make: (function (prim, prim$1, prim$2, prim$3, prim$4, prim$5, prim$6, prim$7, prim$8, prim$9, prim$10, prim$11) {
      var tmp = { };
      if (prim !== undefined) {
        tmp.method = Caml_option.valFromOption(prim);
      }
      if (prim$1 !== undefined) {
        tmp.headers = Caml_option.valFromOption(prim$1);
      }
      if (prim$2 !== undefined) {
        tmp.body = Caml_option.valFromOption(prim$2);
      }
      if (prim$3 !== undefined) {
        tmp.referrer = Caml_option.valFromOption(prim$3);
      }
      if (prim$4 !== undefined) {
        tmp.referrerPolicy = Caml_option.valFromOption(prim$4);
      }
      if (prim$5 !== undefined) {
        tmp.mode = Caml_option.valFromOption(prim$5);
      }
      if (prim$6 !== undefined) {
        tmp.credentials = Caml_option.valFromOption(prim$6);
      }
      if (prim$7 !== undefined) {
        tmp.cache = Caml_option.valFromOption(prim$7);
      }
      if (prim$8 !== undefined) {
        tmp.redirect = Caml_option.valFromOption(prim$8);
      }
      if (prim$9 !== undefined) {
        tmp.integrity = Caml_option.valFromOption(prim$9);
      }
      if (prim$10 !== undefined) {
        tmp.keepalive = Caml_option.valFromOption(prim$10);
      }
      return tmp;
    })
};

function Request__method(prim) {
  return prim.method;
}

function Request_type_(prim) {
  return prim.type;
}

function Request_destination(prim) {
  return prim.destination;
}

function Request_referrerPolicy(prim) {
  return prim.referrerPolicy;
}

function Request_mode(prim) {
  return prim.mode;
}

function Request_credentials(prim) {
  return prim.credentials;
}

function Request_cache(prim) {
  return prim.cache;
}

function Request_redirect(prim) {
  return prim.redirect;
}

var $$Request = {
  _method: Request__method,
  type_: Request_type_,
  destination: Request_destination,
  referrerPolicy: Request_referrerPolicy,
  mode: Request_mode,
  credentials: Request_credentials,
  cache: Request_cache,
  redirect: Request_redirect
};

exports.Method = Method;
exports.ReferrerPolicy = ReferrerPolicy;
exports.RequestType = RequestType;
exports.RequestDestination = RequestDestination;
exports.RequestMode = RequestMode;
exports.RequestCredentials = RequestCredentials;
exports.RequestCache = RequestCache;
exports.RequestRedirect = RequestRedirect;
exports.HeadersInit = HeadersInit;
exports.$$Headers = $$Headers;
exports.BodyInit = BodyInit;
exports.Body = Body;
exports.RequestInit = RequestInit;
exports.$$Request = $$Request;
exports.$$Response = $$Response;
/* No side effect */
