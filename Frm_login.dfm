object Form_login: TForm_login
  Left = 278
  Top = 193
  BorderStyle = bsDialog
  Caption = 'Proporcione por favor su identificación al Sistema'
  ClientHeight = 142
  ClientWidth = 361
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 24
    Width = 95
    Height = 13
    Caption = 'Nombre de Usuario*'
  end
  object Label2: TLabel
    Left = 85
    Top = 46
    Width = 60
    Height = 13
    Caption = 'Contraseña :'
  end
  object lbl_status: TLabel
    Left = 0
    Top = 129
    Width = 361
    Height = 13
    Align = alBottom
    Alignment = taCenter
  end
  object edt_usuario: TEdit
    Left = 149
    Top = 22
    Width = 121
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
    OnChange = edt_usuarioChange
  end
  object edt_passwd: TEdit
    Left = 149
    Top = 44
    Width = 121
    Height = 21
    CharCase = ecUpperCase
    PasswordChar = '*'
    TabOrder = 1
  end
  object btn_aceptar: TBitBtn
    Left = 93
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 2
    OnClick = btn_aceptarClick
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 193
    Top = 88
    Width = 75
    Height = 25
    TabOrder = 3
    Kind = bkCancel
  end
  object dbmanvehi: TDatabase
    DatabaseName = 'dbmanvehi'
    LoginPrompt = False
    Params.Strings = (
      'user name=sa'
      'password=lux')
    SessionName = 'Default'
    Left = 275
    Top = 18
  end
  object qry_login: TQuery
    DatabaseName = 'dbmanvehi'
    SQL.Strings = (
      
        'select idusuario, iniciales, maestro, numpol, login, nombre from' +
        ' car_usuarios a'
      'join pvenfimo b on a.idnombre=b.idnombre'
      'where login = :LOGIN and clave = :CLAVE')
    Left = 307
    Top = 18
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'LOGIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CLAVE'
        ParamType = ptUnknown
      end>
  end
end
