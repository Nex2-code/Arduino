function varargout = ledon(varargin)
% LEDON MATLAB code for ledon.fig
%      LEDON, by itself, creates a new LEDON or raises the existing
%      singleton*.
%
%      H = LEDON returns the handle to a new LEDON or the handle to
%      the existing singleton*.
%
%      LEDON('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in LEDON.M with the given input arguments.
%
%      LEDON('Property','Value',...) creates a new LEDON or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ledon_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ledon_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ledon

% Last Modified by GUIDE v2.5 17-Feb-2020 12:34:13

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ledon_OpeningFcn, ...
                   'gui_OutputFcn',  @ledon_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ledon is made visible.
function ledon_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ledon (see VARARGIN)

% Choose default command line output for ledon
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ledon wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ledon_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
clear all;
global x;
x=serial('COM13','BAUD', 9600); % Make sure the baud rate and COM port is
                                % same as in Arduino IDE
fopen(x);

% --- Executes on button press in ledon.
function ledon_Callback(hObject, eventdata, handles)
% hObject    handle to ledon (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global x;
fprintf(x,1);

% --- Executes on button press in ledoff.
function ledoff_Callback(hObject, eventdata, handles)
% hObject    handle to ledoff (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global x;
fprintf(x,0);